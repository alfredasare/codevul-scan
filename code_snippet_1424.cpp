static int exitcode_proc_open(struct inode *inode, struct file *file)
{
    const char *allowed_paths[] = {"/proc", "/sys", "/etc"};
    char *path = dentry_path(inode);

    if (!is_within_allowed_paths(path, allowed_paths)) {
        return -EPERM;
    }

    return single_open(file, exitcode_proc_show, NULL);
}

bool is_within_allowed_paths(const char *path, const char **allowed_paths)
{
    char *p = path;
    while (*p!= '\0') {
        if (strchr(allowed_paths[0], *p)!= NULL) {
            return true;
        }
        p++;
    }
    return false;
}