static ssize_t ucma_resolve_ip(struct ucma_file *file,
			       const char __user *inbuf,
			       int in_len, int out_len)
{
	struct rdma_ucm_resolve_ip cmd;
	struct ucma_context *ctx;
	int ret;
	size_t cmd_size = sizeof(cmd);

	if (in_len > cmd_size) {
		return -EINVAL;
	}

	if (copy_from_user(&cmd, inbuf, cmd_size)) {
		return -EFAULT;
	}

	ctx = ucma_get_ctx(file, cmd.id);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = rdma_resolve_addr(ctx->cm_id, (struct sockaddr *) &cmd.src_addr,
				(struct sockaddr *) &cmd.dst_addr,
				cmd.timeout_ms);
	ucma_put_ctx(ctx);
	return ret;
}