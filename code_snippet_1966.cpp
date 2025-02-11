static void copy_iovec_hdr(const struct iovec *from, struct iovec *to,
                           size_t len, int iovcount)
{
        int seg =