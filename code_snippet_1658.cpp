irc_ctcp_dcc_filename_without_quotes(const char *filename)
{
    char *sanitized_filename = NULL;
    char *temp = NULL;

    temp = strdup(filename);
    sanitized_filename = sanitize_filename(temp);
    free(temp);

    return sanitized_filename;
}

char *sanitize_filename(const char *filename)
{
    char *sanitized_filename = NULL;
    char buffer[256] = {0}; // Allocate a buffer for the sanitized filename
    int i = 0;

    while (*filename) {
        if (is_path_traversal_char(*filename)) {
            // Replace potentially malicious characters with a safe character
            buffer[i] = '\\';
            i++;
        } else if (*filename!= '/') {
            buffer[i] = *filename;
            i++;
        }
        filename++;
    }

    buffer[i] = '\0'; // Null-terminate the buffer
    sanitized_filename = strdup(buffer);

    return sanitized_filename;
}

int is_path_traversal_char(char c)
{
    return c == '.' || c == '/';
}