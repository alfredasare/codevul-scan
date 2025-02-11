const char *gnu_basename(const char *path) {
    size_t path_len = strlen(path);
    const char *last_slash = strrchr(path, '/');
    if (!last_slash || last_slash >= path + path_len) {
        return path;
    }
    return last_slash + 1;
}