static ssize_t proxy_readlink(FsContext *fs_ctx, V9fsPath *fs_path, char *buf, size_t bufsz)
{
    int retval;
    char formatted_buf[PATH_MAX];

    retval = v9fs_request(fs_ctx->private, T_READLINK, formatted_buf, fs_path, sizeof(formatted_buf));
    if (retval < 0) {
        errno = -retval;
        return -1;
    }

    snprintf(buf, bufsz, "%s", formatted_buf);
    return strlen(buf);
}