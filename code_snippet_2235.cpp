check_options()
{
    if (logfile_fd >= 0) {
        // Validate the logfile_fd path
        char* path = realpath(logfile_fd, NULL);
        if (path == NULL ||!is_within_allowed_directory(path)) {
            close(logfile_fd);
        } else {
            free(path);
        }
    }
}

// Helper function to check if the path is within an allowed directory
bool is_within_allowed_directory(const char* path) {
    // Define a whitelist of allowed directories
    const char* allowed_dirs[] = {"/var/log", "/opt/logs"};
    for (int i = 0; i < sizeof(allowed_dirs) / sizeof(allowed_dirs[0]); i++) {
        if (strchr(path, '/') && strcmp(strchr(path, '/)+1, allowed_dirs[i]) == 0) {
            return true;
        }
    }
    return false;
}