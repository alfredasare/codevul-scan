COMPAT_SYSCALL_DEFINE3(rt_sigqueueinfo,
                                compat_pid_t, pid,
                                int, sig,
                                struct compat_siginfo __user *, uinfo)
{
	siginfo_t info;
	size_t uinfo_len = strnlen(uinfo, sizeof(struct compat_siginfo));

	if (uinfo_len >= sizeof(struct compat_siginfo)) {
		printk(KERN_ERR "Invalid user-provided data\n");
		return -EINVAL;
	}

	if (copy_from_user(&info, uinfo, uinfo_len))
		return -EFAULT;

	/* Zero-out the rest of the buffer for safety */
	memset(&info + uinfo_len, 0, sizeof(struct siginfo) - uinfo_len);

	return do_rt_sigqueueinfo(pid, sig, &info);
}