
SYSCALL_DEFINE6(io_uring_enter, unsigned int, fd, u32, to_submit,
		u32, min_complete, u32, flags, const void __user *, argp,
		size_t, argsz)
{
	struct io_ring_ctx *ctx;
	int submitted = 0;
	struct fd f;
	long ret;

	io_run_task_work();

	if (unlikely(flags & ~(IORING_ENTER_GETEVENTS | IORING_ENTER_SQ_WAKEUP |
			       IORING_ENTER_SQ_WAIT | IORING_ENTER_EXT_ARG)))
		return -EINVAL;

	f = fdget(fd);
	if (unlikely(!f.file))
		return -EBADF;

	ret = -EOPNOTSUPP;
	if (unlikely(f.file->f_op != &io_uring_fops))
		goto out_fput;

	ret = -ENXIO;
	ctx = f.file->private_data;
	if (unlikely(!percpu_ref_tryget(&ctx->refs)))
		goto out_fput;

	ret = -EBADFD;
	if (unlikely(ctx->flags & IORING_SETUP_R_DISABLED))
		goto out;

	/*
	 * For SQ polling, the thread will do all submissions and completions.
	 * Just return the requested submit count, and wake the thread if
	 * we were asked to.
	 */
	ret = 0;
	if (ctx->flags & IORING_SETUP_SQPOLL) {
		io_cqring_overflow_flush(ctx, false);

		ret = -EOWNERDEAD;
		if (unlikely(ctx->sq_data->thread == NULL)) {
			goto out;
		}
		if (flags & IORING_ENTER_SQ_WAKEUP)
			wake_up(&ctx->sq_data->wait);
		if (flags & IORING_ENTER_SQ_WAIT) {
			ret = io_sqpoll_wait_sq(ctx);
			if (ret)
				goto out;
		}
		submitted = to_submit;
	} else if (to_submit) {
		ret = io_uring_add_task_file(ctx);
		if (unlikely(ret))
			goto out;
		mutex_lock(&ctx->uring_lock);
		submitted = io_submit_sqes(ctx, to_submit);
		mutex_unlock(&ctx->uring_lock);

		if (submitted != to_submit)
			goto out;
	}
	if (flags & IORING_ENTER_GETEVENTS) {
		const sigset_t __user *sig;
		struct __kernel_timespec __user *ts;

		ret = io_get_ext_arg(flags, argp, &argsz, &ts, &sig);
		if (unlikely(ret))
			goto out;

		min_complete = min(min_complete, ctx->cq_entries);

		/*
		 * When SETUP_IOPOLL and SETUP_SQPOLL are both enabled, user
		 * space applications don't need to do io completion events
		 * polling again, they can rely on io_sq_thread to do polling
		 * work, which can reduce cpu usage and uring_lock contention.
		 */
		if (ctx->flags & IORING_SETUP_IOPOLL &&
		    !(ctx->flags & IORING_SETUP_SQPOLL)) {
			ret = io_iopoll_check(ctx, min_complete);
		} else {
			ret = io_cqring_wait(ctx, min_complete, sig, argsz, ts);
		}
	}

out:
	percpu_ref_put(&ctx->refs);
out_fput:
	fdput(f);
	return submitted ? submitted : ret;