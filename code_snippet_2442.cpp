#include <string.h>
#include <iconv.h>

is_path_absolute(const char *path) {
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-";
    char *input_copy = strdup(path);
    char *p = input_copy;
    while (*p) {
        if (strchr(allowed_chars, *p) == NULL) {
            free(input_copy);
            return 0;
        }
        p++;
    }
    free(input_copy);

    iconv_t cd = iconv_open("UTF-8", "ASCII");
    char *normalized_path = iconv((iconv_t)cd, path, strlen(path), NULL, 0);
    iconv_close(cd);

    if (normalized_path[0] == '/') {
        free(normalized_path);
        return 1;
    }
    free(normalized_path);
    return 0;
}