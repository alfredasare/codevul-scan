selaGetCount(SELA *sela)
{
    PROCNAME("selaGetCount");

    if (!sela)
        return ERROR_INT("sela not defined", procName, 0);

    // Validate and sanitize the input path
    char* sanitized_path = sanitize_path(sela->path);
    if (!sanitized_path) {
        return ERROR_INT("Invalid path", procName, 0);
    }

    // Access the file within the intended directory
    int count = access_file(sanitized_path);
    free(sanitized_path);

    return count;
}

char* sanitize_path(char* path)
{
    char* sanitized_path = malloc(strlen(path) + 1);
    strcpy(sanitized_path, path);

    // Remove any directory traversal sequences
    sanitized_path = remove_traversal_sequences(sanitized_path);

    return sanitized_path;
}

char* remove_traversal_sequences(char* path)
{
    static char buffer[1024];
    char* p = buffer;

    while (*path) {
        if (strchr("../", *path)) {
            // Replace directory traversal sequences with an empty string
            *p++ = '\0';
        } else {
            *p++ = *path++;
        }
    }

    *p = '\0';
    return buffer;
}