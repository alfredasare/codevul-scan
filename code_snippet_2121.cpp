#define MAX_PATH_LENGTH 256
#define ALLOWED_DIRECTORY "/allowed/directory"

static int apparmor_path_truncate(const struct path *path)
{
    char resolved_path[MAX_PATH_LENGTH];
    if (realpath_r(path->dentry->d_name, resolved_path) == NULL) {
        return -1;
    }

    if (strncmp(resolved_path, ALLOWED_DIRECTORY, strlen(ALLOWED_DIRECTORY)) != 0) {
        return -1;
    }

    return common_perm_path(OP_TRUNC, path, MAY_WRITE | AA_MAY_META_WRITE);
}