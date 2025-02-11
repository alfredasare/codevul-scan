int readlink_and_make_absolute_root(const char *root, const char *path, char **ret) {
    _cleanup_free_ char *target = NULL, *t = NULL;
    const char *full;
    int r;

    full = prefix_roota(root, path);
    r = readlink_malloc(full, &target);
    if (r < 0)
        return r;

    t = file_in_same_dir(path, target);
    if (!t)
        return -ENOMEM;

    // Verify ownership and permissions of t
    struct stat statbuf;
    if (stat(t, &statbuf) == -1) {
        return -errno;
    }
    if (!S_ISREG(statbuf.st_mode)) {
        return -EISDIR;
    }
    if (statbuf.st_uid!= geteuid() || statbuf.st_gid!= getegid()) {
        return -EPERM;
    }

    *ret = t;
    t = NULL;

    return 0;
}