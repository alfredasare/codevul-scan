static void bandwidth_create_run_file(pid_t pid) {
    char *fname;
    if (asprintf(&fname, "%s/%d-bandwidth", RUN_FIREJAIL_BANDWIDTH_DIR, (int) pid) == -1)
        errExit("asprintf");

    struct stat s;
    if (stat(fname, &s, AT_SYMLINK_NOFOLLOW)!= 0) {
        free(fname);
        return;
    }

    if (!S_ISREG(s.st_mode)) {
        fprintf(stderr, "Error: file is not a regular file\n");
        exit(1);
    }

    if (access(fname, W_OK)!= 0) {
        fprintf(stderr, "Error: insufficient permissions\n");
        exit(1);
    }

    FILE *fp = fopen(fname, "w");
    if (fp) {
        SET_PERMS_STREAM(fp, 0, 0, 0644);
        fclose(fp);
    } else {
        fprintf(stderr, "Error: cannot create bandwidth file\n");
        exit(1);
    }

    free(fname);
}