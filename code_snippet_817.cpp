static ssize_t fuse_direct_read_iter(struct kiocb *iocb, struct iov_iter *to)
{
    struct fuse_io_priv io = {.async = 0 };

    // Validate the file descriptor
    if (iocb->ki_filp == NULL ||!filp_valid(iocb->ki_filp)) {
        return -EBADF;
    }

    // Sanitize the file descriptor
    if (iocb->ki_filp->f_flags & O_PATH) {
        return -EBADFD;
    }

    return __fuse_direct_read(&io, to, &iocb->ki_pos);
}