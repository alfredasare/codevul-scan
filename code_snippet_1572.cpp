static int proxy_chmod(FsContext *fs_ctx, V9fsPath *fs_path, FsCred *credp)
{
    int retval;
    if (fs_ctx->private->request_type!= T_CHMOD) {
        return -EINVAL;
    }
    if (!fs_path ||!credp) {
        return -EINVAL;
    }
    if (chmod(fs_path->path, credp->fc_mode)!= 0) {
        retval = -errno;
    } else {
        retval = 0;
    }
    return retval;
}