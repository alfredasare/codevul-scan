SYSCALL_DEFINE5(recvmmsg, int, fd, struct mmsghdr __user *, mmsg,
	unsigned int, vlen, unsigned int, flags,
	struct timespec __user *, timeout)
{
	//... (rest of the function remains the same)

	if (timeout) {
		struct timespec timeout_sys;

		if (copy_from_user(&timeout_sys, timeout, sizeof(timeout_sys)) ||
		    unlikely(!is_aligned(&timeout_sys, sizeof(timeout_sys))))
			return -EFAULT;

		datagrams = __sys_recvmmsg(fd, mmsg, vlen, flags, &timeout_sys);

		if (datagrams > 0 &&
		    copy_to_user(timeout, &timeout_sys, sizeof(timeout_sys)))
			datagrams = -EFAULT;
	}
	return datagrams;
}

static inline bool is_aligned(void *ptr, size_t size)
{
	return ((uintptr_t)ptr % size == 0);
}