int user_path_at(int dfd, const char __user *name, unsigned flags, struct path *path)
{
    size_t len = strlen(name);
    if (len > PATH_MAX) {
        return -ENAMETOOLONG;
    }
    return user_path_at_empty(dfd, name, flags, path, NULL);
}