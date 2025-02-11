void fslib_duplicate(const char *full_path) {
    assert(full_path);

    struct stat s;
    if (stat(full_path, &s)!= 0 || s.st_uid!= 0 || access(full_path, R_OK))
        return;

    char *dest_dir = build_dest_dir(full_path);
    char path_buffer[PATH_MAX];
    strcpy(path_buffer, full_path);

    char *ptr = strrchr(path_buffer, '/');
    if (!ptr || ptr > path_buffer + PATH_MAX - 1)
        return;
    ptr++;

    if (*ptr == '\0')
        return;

    size_t name_len = strlen(dest_dir) + strlen(ptr) + 2;
    char *name = malloc(name_len);
    sprintf(name, "%s/%s", dest_dir, ptr);

    if (stat(name, &s) == 0) {
        free(name);
        return;
    }
    free(name);

    if (arg_debug || arg_debug_private_lib)
        printf("    copying %s to private %s\n", full_path, dest_dir);

    sbox_run(SBOX_ROOT| SBOX_SECCOMP, 4, PATH_FCOPY, "--follow-link", full_path, dest_dir);
    report_duplication(full_path);
    lib_cnt++;
}