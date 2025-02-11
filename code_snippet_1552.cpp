void gdDumpRect(const char *msg, gdRectPtr r)
{
    static const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 _-.";
    size_t msg_len = strlen(msg);
    char buffer[1024] = {0};

    for (size_t i = 0; i < msg_len; i++) {
        if (strchr(allowed_chars, msg[i]) == NULL) {
            // Input contains invalid character, reject the input
            printf("Invalid input: '%c'\n");
            return;
        }
    }

    snprintf(buffer, sizeof(buffer), "%s (%i, %i) (%i, %i)\n", msg, r->x, r->y, r->width, r->height);
    printf(buffer);
}