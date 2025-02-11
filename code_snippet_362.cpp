cdf_read(const cdf_info_t *info, off_t off, void *buf, size_t len)
{
    const off_t max_offset = info->i_size - len;
    if (off < 0 || off > max_offset || off + len > max_offset) {
        errno = EINVAL;
        return -1;
    }

    if (info->i_buf != NULL && info->i_len >= (size_t)(off + len)) {
        (void)memcpy(buf, &info->i_buf[off], len);
        return (ssize_t)len;
    }

    if (info->i_fd == -1)
        return -1;

    if (pread(info->i_fd, buf, len, off) != (ssize_t)len)
        return -1;

    return (ssize_t)len;
}