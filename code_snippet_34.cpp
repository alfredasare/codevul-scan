static int read_public_key(RSA *rsa)
{
    //...

    sc_path_t path;
    char *allowed_paths[] = {"/path/to/allowed/keys", NULL};

    r = select_app_df();
    if (r)
        return 1;

    sc_format_path("I1012", &path);
    if (strchr(path, '/') ||!validate_path(path, allowed_paths)) {
        fprintf(stderr, "Invalid path: %s\n", path);
        return 2;
    }

    char *normalized_path = basename(path);
    if (!normalized_path ||!strcmp(normalized_path, "I1012")) {
        fprintf(stderr, "Invalid normalized path: %s\n", normalized_path);
        return 2;
    }

    r = fread(buf, 1, bufsize, file);
    if (r < 0) {
        fprintf(stderr, "Unable to read public key file: %s\n", sc_strerror(r));
        return 2;
    }
    //...
}