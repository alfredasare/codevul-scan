hostname_map(char* hostname) {
    int len, n;
    static char* list[] = { SERVER_NAME_LIST }; // assume SERVER_NAME_LIST is a list of valid directory paths

    len = strlen(hostname);
    for (n = 0; n < sizeof(list) / sizeof(*list); ++n) {
        if (strncasecmp(hostname, list[n], len) == 0) {
            if (path_is_within_expected_dir(list[n])) {
                return &list[n][len];
            }
        }
    }
    return (char*) 0;
}

bool path_is_within_expected_dir(char* path) {
    // Implement your own logic to check if the path is within the expected directory structure
    // For example, you can use a whitelist of allowed directories or check if the path starts with a certain prefix
    // Return true if the path is valid, false otherwise
}