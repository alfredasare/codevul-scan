buffer_add_range(int fd, struct evbuffer *evb, struct range *range)
{
	char	buf[BUFSIZ];
	size_t	n, range_sz;
	ssize_t	nread;
	if (lseek(fd, range->start, SEEK_SET) == -1)
		return (0);
	range_sz = range->end - range->start + 1;
	while (range_sz) {
		n = MINIMUM(range_sz, sizeof(buf));
		if ((nread = read(fd, buf, n)) == -1)
			return (0);
		if (nread > 0 && nread < n) {
            n = nread;
        }
		evbuffer_add(evb, buf, n);
		range_sz -= n;
	}
	return (1);
}