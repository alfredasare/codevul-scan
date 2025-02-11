load(const char *magicfile, int flags)
{
    struct magic_set *magic = magic_open(flags);
    if (magic == NULL) {
        (void)fprintf(stderr, "%s: %s\n", progname, strerror(errno));
        return NULL;
    }

    // Validate and sanitize the magicfile parameter
    const char *allowed_dirs[] = {"/usr/local/magic/", "/usr/share/magic/"};
    const size_t num_allowed_dirs = sizeof(allowed_dirs) / sizeof(allowed_dirs[0]);
    char *sanitized_magicfile = NULL;
    char *dir = NULL;
    char *file = NULL;
    char *token = strtok_r(magicfile, "/", &dir);

    while (token!= NULL) {
        if (strchr(token, '.')!= NULL) {
            file = token;
            break;
        }
        token = strtok_r(NULL, "/", &dir);
    }

    if (token == NULL || strlen(file) == 0 || strlen(dir) == 0) {
        (void)fprintf(stderr, "%s: Invalid file path\n", progname);
        magic_close(magic);
        return NULL;
    }

    for (size_t i = 0; i < num_allowed_dirs; i++) {
        if (strcmp(dir, allowed_dirs[i]) == 0) {
            sanitized_magicfile = malloc(strlen(allowed_dirs[i]) + strlen(file) + 2);
            sprintf(sanitized_magicfile, "%s/%s", allowed_dirs[i], file);
            break;
        }
    }

    if (sanitized_magicfile == NULL) {
        (void)fprintf(stderr, "%s: Invalid file path\n", progname);
        magic_close(magic);
        return NULL;
    }

    if (access(sanitized_magicfile, R_OK)!= 0) {
        (void)fprintf(stderr, "%s: %s\n", progname, strerror(errno));
        magic_close(magic);
        free(sanitized_magicfile);
        return NULL;
    }

    if (magic_load(magic, sanitized_magicfile) == -1) {
        (void)fprintf(stderr, "%s: %s\n", progname, magic_error(magic));
        magic_close(magic);
        free(sanitized_magicfile);
        return NULL;
    }

    free(sanitized_magicfile);
    return magic;
}