static int get_int_option(const char* options, const char* option_name,
                         int base, int default_value)
{
    const char* p = get_option(options, option_name);

    if (p == NULL)
        return default_value;

    // Validate the input string
    size_t len = strlen(p);
    if (len > MAX_OPTION_LENGTH) {
        return default_value; // or handle the error
    }

    // Validate the input string using a whitelist approach
    const char* whitelist = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.";
    for (size_t i = 0; i < len; i++) {
        if (strchr(whitelist, p[i]) == NULL) {
            return default_value; // or handle the error
        }
    }

    return strtol(p, NULL, base);
}