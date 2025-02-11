#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static void remove_pidfile(const char *pid_file) {
    if (pid_file == NULL) {
        return;
    }

    char *canonical_path = realpath(pid_file, NULL);
    if (canonical_path == NULL ||!stat(canonical_path, &st) ||!S_ISREG(st.st_mode)) {
        free(canonical_path);
        return;
    }

    char *tmpdir = strdup("/tmp/.");

    char *tmpfile = malloc(strlen(tmpdir) + strlen(pid_file) + 10);
    sprintf(tmpfile, "%s/%s.XXXXXX", tmpdir, pid_file);
    int fd = mkstemp(tmpfile);
    free(tmpfile);

    if (fd!= -1) {
        close(fd);
    } else {
        fprintf(stderr, "Could not create temporary file.\n");
    }

    free(tmpdir);
    unlink(tmpfile);
    free(tmpfile);
}