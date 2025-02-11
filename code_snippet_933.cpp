static ssize_t fuse_direct_read_iter(struct kiocb *iocb, struct iov_iter *to)
{
	struct fuse_io_priv io = { .async = 0, .file = iocb->ki_filp };
	ssize_t retval;
	mm_segment_t oldfs;

	oldfs = get_fs();
	set_fs(KERNEL_DS);
	retval = __fuse_direct_read(&io, to, &iocb->ki_pos);
	set_fs(oldfs);

	return retval;
}