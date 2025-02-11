static void save_pid(const pid_t pid, const char *pid_file) {
    FILE *fp;
    if (pid_file == NULL)
        return;

    fp = fopen(pid_file, "w");
    if (fp == NULL) {
        fprintf(stderr, "Could not open the pid file %s for writing\n", pid_file);
        return;
    }

    if (fprintf(fp, "%jd\n", (intmax_t)pid) < 0) {
        fprintf(stderr, "Failed to write the pid to the file %s\n", pid_file);
        fclose(fp);
        return;
    }

    if (fclose(fp) == -1) {
        fprintf(stderr, "Could not close the pid file %s.\n", pid_file);
    }
}