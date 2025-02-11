#include <string.h>
#include <stdlib.h>

#define MAX_PATH 1024

static struct mschmd_header *chmd_open(struct mschm_decompressor *base,
                                       const char *filename)
{
    char trusted_path[MAX_PATH];
    char *expanded_path;
    snprintf(trusted_path, sizeof(trusted_path), "/path/to/trusted/directory/%s", basename(filename));

    expanded_path = realpath(filename, NULL);
    if (!expanded_path) {
        return NULL;
    }

    if (strncmp(expanded_path, trusted_path, strlen(trusted_path)) != 0) {
        free(expanded_path);
        return NULL;
    }

    free(expanded_path);

    return chmd_real_open(base, filename, 1);
}