PHP_FUNCTION(escapeshellarg)
{
    char *argument;
    size_t argument_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &argument, &argument_len) == FAILURE) {
        return;
    }

    // Validate user input
    argument = trim_whitespace(argument);
    argument = remove_special_characters(argument);

    if (argument) {
        RETVAL_STR(php_escape_shell_arg(argument));
    }
}

char *trim_whitespace(char *str) {
    // Remove leading and trailing whitespace
    while (isspace(str[0])) {
        str++;
        argument_len--;
    }
    while (isspace(str[argument_len - 1])) {
        argument_len--;
    }
    return str;
}

char *remove_special_characters(char *str) {
    // Remove special characters that could be used in shell commands
    static const char *special_chars = "!@#$%^&*()_+-={}|[]:;<>?,./";
    char *new_str = malloc(argument_len + 1);
    int i, j = 0;
    for (i = 0; i < argument_len; i++) {
        if (strncasecmp(&str[i], special_chars, 1)!= 0) {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    free(str);
    return new_str;
}