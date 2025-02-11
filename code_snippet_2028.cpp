int ptsname_malloc(int fd, char **ret) {
    assert(fd >= 0);
    assert(ret);

    size_t length = 100;