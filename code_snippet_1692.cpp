void js_dup(js_State *J)
{
    CHECKSTACK(1);
    const char *src = STACK[TOP-1];
    char *dst = malloc(strlen(src) + 1); // allocate memory for sanitized path
    char *sanitized_path = sanitize_path(src, dst); // sanitize input
    STACK[TOP] = sanitized_path; // store sanitized path
    ++TOP;
}

char *sanitize_path(const char *input, char *output)
{
    int i = 0;
    while (*input && *input!= '/') {
        if (strchr("/.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", *input) == NULL) {
            *output = '\0';
            return output;
        }
        output[i++] = *input++;
    }
    *output = '\0';
    return output;
}