int ptsname_malloc(int fd, char **ret) {
    size_t l = 256; 

    assert(fd >= 0);
    assert(ret);

    for (;;) {
        char *c;

        c = new(char, l);
        if (!c)
            return -ENOMEM;

        if (ptsname_r(fd, c, l) == 0) {
            *ret = c;
            return 0;
        }
        if (errno!= ERANGE) {
            free(c);
            return -errno;
        }

        size_t max_size = SIZE_MAX / 2; 
        l = (l < max_size)? l : max_size; 

        free(c);

        if (l > SIZE_MAX / 2) 
            return -ENOMEM;
    }
}