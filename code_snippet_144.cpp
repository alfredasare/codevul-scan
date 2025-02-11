static uint8_t *smbXcli_iov_concat(TALLOC_CTX *mem_ctx,
                                   const struct iovec *iov,
                                   int count)
{
    ssize_t buflen;
    uint8_t *buf;
    size_t iov_len = 0;

    buflen = iov_buflen(iov, count);
    if (buflen == -1) {
        return NULL;
    }

    // Check if the input data exceeds the allocated buffer size
    if (iov_len > buflen) {
        return NULL; // or handle the error appropriately
    }

    buf = talloc_array(mem_ctx, uint8_t, buflen);
    if (buf == NULL) {
        return NULL;
    }

    iov_buf(iov, count, buf, buflen);

    return buf;
}