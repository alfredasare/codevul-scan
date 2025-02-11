COMPAT_SYSCALL_DEFINE3(rt_sigqueueinfo,
			compat_pid_t, pid,
			int, sig,
			struct compat_siginfo __user *, uinfo)
{
	siginfo_t info;
	int ret = copy_siginfo_from_user32(&info, uinfo);
	int num_signals = 0; // Initialize a counter for the number of signals

	if (unlikely(ret))
		return ret;

	do {
		num_signals++;
		if (!do_rt_sigqueueinfo(pid, sig, &info))
			break;
		sig++; // Increment the signal number for the next iteration
	} while (num_signals < sig); // Continue until all signals have been sent

	return 0;
}