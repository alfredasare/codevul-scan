int check_rss_recipient(const char *recipient) {
    cupsd_subscription_t *sub;
    int ret = 1; // assume invalid input

    if (!recipient || strcasecmp(recipient, "") == 0 || strchr(recipient, '?') || strchr(recipient, '<') || strchr(recipient, '>') || strchr(recipient, '|') || strchr(recipient, '{') || strchr(recipient, '}') || strchr(recipient, '[') || strchr(recipient, ']') || strchr(recipient, '(') || strchr(recipient, ')') || strchr(recipient, ';') || strchr(recipient, ':') || strchr(recipient, '\'') || strchr(recipient, '"') || strchr(recipient, '`')) {
        // invalid input, return error
        return ret;
    }

    // if we reach this point, the input is valid
    ret = 0;
    return ret;
}