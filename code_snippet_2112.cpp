int dup_fd_cloexec(int oldfd, int lowfd)
{
    if (oldfd < 0 || oldfd > FD_SETSIZE || lowfd < 0 || lowfd > FD_SETSIZE) {
        return -1;
    }
#ifdef F_DUPFD_CLOEXEC
    return fcntl(oldfd, F_DUPFD_CLOEXEC, lowfd);
#else
    int fd = dup(oldfd);
    if (fd < 0)
        return fd;
    int flags = fcntl(fd, F_GETFD);
    if (flags < 0)
        goto unwind;
    if (fcntl(fd, F_SETFD, flags | FD_CLOEXEC) < 0)
        goto unwind;
    return fd;
unwind:
    errno = errno;
    close(fd);
    return -1;
#endif
}