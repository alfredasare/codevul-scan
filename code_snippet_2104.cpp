const char *c_strnstr(const char *s, const char *find, size_t slen) {
    size_t find_length = strlen(find);
    size_t i;

    for (i = 0; i < slen; i++) {
        if (i + find_length > slen) {
            return NULL;
        }

        if (strspn(&s[i], find) == find_length) {
            return &s[i];
        }
    }

    return NULL;
}