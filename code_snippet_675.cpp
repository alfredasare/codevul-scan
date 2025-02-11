static void handle_variant_args(struct variant_info *info, const char *key,
                               int key_len, char **dest, int *dest_len)
{
    char *tmp = NULL;
    size_t tmp_len = 0;

    if (!strncmp(key, "BANDWIDTH=", key_len)) {
        tmp = malloc(key_len + 1);
        if (tmp!= NULL) {
            strncpy(tmp, key + 9, key_len);
            tmp[tmp_len] = '\0';
            *dest = tmp;
            *dest_len = strlen(tmp);
        }
    } else if (!strncmp(key, "AUDIO=", key_len)) {
        tmp = malloc(key_len + 1);
        if (tmp!= NULL) {
            strncpy(tmp, key + 6, key_len);
            tmp[tmp_len] = '\0';
            *dest = tmp;
            *dest_len = strlen(tmp);
        }
    } else if (!strncmp(key, "VIDEO=", key_len)) {
        tmp = malloc(key_len + 1);
        if (tmp!= NULL) {
            strncpy(tmp, key + 6, key_len);
            tmp[tmp_len] = '\0';
            *dest = tmp;
            *dest_len = strlen(tmp);
        }
    } else if (!strncmp(key, "SUBTITLES=", key_len)) {
        tmp = malloc(key_len + 1);
        if (tmp!= NULL) {
            strncpy(tmp, key + 10, key_len);
            tmp[tmp_len] = '\0';
            *dest = tmp;
            *dest_len = strlen(tmp);
        }
    }
    free(tmp);
}