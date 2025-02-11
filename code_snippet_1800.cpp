char *url_full_path(const struct url *url) {
    if (url == NULL) {
        return NULL;
    }

    int length = full_path_length(url);
    if (length < 0 || length > INT_MAX - 1) {
        return NULL;
    }

    char *full_path = xmalloc(length + 1);
    if (full_path == NULL) {
        return NULL;
    }

    full_path_write(url, full_path);
    full_path[length] = '\0';

    return full_path;
}