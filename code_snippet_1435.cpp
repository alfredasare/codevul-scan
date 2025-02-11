pidfile(pid\_file))
return;

char resolved\_path[4096];
if (realpath(pid\_file, resolved\_path) == NULL) {
fprintf(stderr, "Error resolving path: %s\n", strerror(errno));
return;
}

int fd = open(resolved\_path, O\_WRONLY|O\_EXCL);
if (fd == -1) {
fprintf(stderr, "Could not open or create the pid file %s: %s\n", resolved\_path, strerror(errno));
return;
}

if (close(fd) != 0) {
fprintf(stderr, "Error closing the pid file %s: %s\n", resolved\_path, strerror(errno));
}

if (unlink(resolved\_path) != 0) {
fprintf(stderr, "Could not remove the pid file %s.\n", resolved\_path);
}

}