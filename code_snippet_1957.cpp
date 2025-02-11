static ssize_t proxy_readlink(FsContext *fs_ctx, V9fsPath *fs_path,
                              char *buf, size_t bufsz)
{
    int retval;
    size_t bytes_read = min(bufsz, pathconf(fs_path->path, _PC_PATH_MAX));

    retval = v9fs_request(fs_ctx->private, T_READLINK, buf, fs_path, bytes_read);
    if (retval < 0) {
        errno = -retval;
        return -1;
    }

    buf[bytes_read] = '\0';

    return bytes_read;
}