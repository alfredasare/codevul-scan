static struct mschmd_header *chmd_open(struct mschmd_decompressor *base, const char *filename)
{
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-";
    for (int i = 0; i < strlen(filename); i++) {
        if (strchr(allowed_chars, filename[i]) == NULL) {
            return NULL;
        }
    }
    if (strchr(filename, '/') || strstr(filename, "..")) {
        return NULL;
    }
    return chmd_real_open(base, filename, 1);
}