static int apparmor_path_truncate(const struct path *path)
{
    size_t path_len = strlen(path->buf);
    if (path_len > PATH_MAX) {
        return -EINVAL;
    }

    char* truncated_path = strndup(path->buf, PATH_MAX);
    if (!truncated_path) {
        return -ENOMEM;
    }

    return common_perm_path(OP_TRUNC, truncated_path, MAY_WRITE | AA_MAY_META_WRITE);
}