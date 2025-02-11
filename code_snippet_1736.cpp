static int proxy_chmod(FsContext *fs_ctx, V9fsPath *fs_path, FsCred *credp)
{
    int retval;
    int max_retries = 5;
    int retries = 0;

    while ((retval = v9fs_request(fs_ctx->private, T_CHMOD, NULL, fs_path,
                                 credp->fc_mode)) == -EAGAIN && retries < max_retries) {
        retries++;
    }

    if (retval < 0 && retval != -EAGAIN) {
        errno = -retval;
    }
    return retval;
}