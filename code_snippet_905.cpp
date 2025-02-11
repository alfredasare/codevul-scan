code:


buffer_add_range(int fd, struct evbuffer *evb, struct range *range)
{
    char *buf = malloc(BUFSIZ); 
    size_t n, range_sz;
    ssize_t nread;
    if (lseek(fd, range->start, SEEK_SET) == -1)
        return (0);
    if (range->start < 0 || range->end > 0xFFFFFFFF)
        return (0);
    range_sz = range->end - range->start + 1;
    while (range_sz) {
        n = MINIMUM(range_sz, BUFSIZ);
        if ((nread = recvfrom(fd, buf, n, 0, NULL, NULL)) == -1)
            return (0);
        evbuffer_add(evb, buf, nread);
        range_sz -= nread;
    }
    free(buf); 
    return (1);
}