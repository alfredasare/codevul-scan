static bool name_is_illegal(const char *name)
{
    if (!name ||!*name) {
        return true;
    }

    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._";
    size_t allowed_len = strlen(allowed_chars);

    while (*name) {
        char c = *name;
        bool found = false;

        for (size_t i = 0; i < allowed_len; i++) {
            if (c == allowed_chars[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            return true;
        }

        name++;
    }

    return false;
}