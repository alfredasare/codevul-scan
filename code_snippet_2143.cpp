static void bandwidth_create_run_file(pid_t pid) {
    char *fname;
    if (asprintf(&fname, "%s/%d-bandwidth", RUN_FIREJAIL_BANDWIDTH_DIR, (int) pid) == -1)
        errExit("asprintf");

    char resolved_path[PATH_MAX];
    if (realpath(fname, resolved_path) == NULL) {
        fprintf(stderr, "Error: cannot resolve path for bandwidth file\n");
        exit(1);
    }

    int fd = open(resolved_path, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd != -1) {
        close(fd);
    } else {
        fprintf(stderr, "Error: cannot create bandwidth file\n");
        exit(1);
    }

    free(fname);
}