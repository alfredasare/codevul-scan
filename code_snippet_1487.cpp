int readlink_and_make_absolute_root(const char *root, const char *path, char **ret) {
    _cleanup_free_ char *target = NULL, *t = NULL, *target_backup = NULL;
    const char *full;
    int r;

    full = prefix_roota(root, path);
    r = readlink_malloc(full, &target);
    if (r < 0)
        return r;