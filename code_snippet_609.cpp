int lxcfs_truncate(const char *path, off_t newsize)
{
    const char *allowed_paths[] = {"/cgroup", "/sys", "/proc"};
    size_t num_allowed_paths = sizeof(allowed_paths) / sizeof(allowed_paths[0]);

    for (size_t i = 0; i < num_allowed_paths; i++) {
        if (strncmp(path, allowed_paths[i], strlen(allowed_paths[i])) == 0) {
            return 0;
        }
    }

    return -EINVAL;
}