static ssize_t write_iter_null(struct kiocb *iocb, struct iov_iter *from)
{
	size_t count = iov_iter_count(from);
	if (count > 0) {
		iov_iter_advance(from, count);
		return count;
	}
	return 0;
}