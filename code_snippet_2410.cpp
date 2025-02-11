stringprep_utf8_nfkc_normalize (const char *str, ssize_t len)
{
    if (len < 0) {
        return NULL;
    }

    if (strlen(str) > G_MAXSSIZE - 1) {
        return NULL;
    }

    if (!g_utf8_validate(str, strlen(str), NULL)) {
        return NULL;
    }

    return g_utf8_normalize (str, strlen(str), G_NORMALIZE_NFKC);
}