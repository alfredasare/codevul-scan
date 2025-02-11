int dup_fd_cloexec(int oldfd, int lowfd)
{
	int fd, flags, errno_save;

#ifdef F_DUPFD_CLOEXEC
	fd = fcntl(oldfd, F_DUPFD_CLOEXEC, lowfd);
	if (fd >= 0)
		return fd;
#else
	fd = dup(oldfd);
	if (fd < 0)
		return fd;

	flags = fcntl(fd, F_GETFD);
	if (flags < 0)
		goto unwind;

	/* Set the close-on-exec flag */
	flags |= FD_CLOEXEC;
	if (fcntl(fd, F_SETFD, flags) < 0)
		goto unwind;
#endif

	return fd;

unwind:
	errno_save = errno;
	close(fd);
	errno = errno_save;

	return -1;
}