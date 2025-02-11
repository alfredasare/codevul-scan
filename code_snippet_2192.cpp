int pt_removexattr(FsContext *ctx, const char *path, const char *name)
{
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        return -ENOENT;
    }

    if ((statbuf.st_mode & S_IWUSR) == 0) {
        return -EPERM;
    }

    return local_removexattr_nofollow(ctx, path, name);
}