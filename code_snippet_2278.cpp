#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static tsize_t TIFFWriteBlob(thandle_t image, tdata_t data, tsize_t size) {
    tsize_t count;
    char *image_path = get_image_path(image);

    if (!is_allowed_directory(image_path)) {
        return -1;
    }

    char *sanitized_data_path = realpath(data, NULL);

    if (sanitized_data_path == NULL) {
        return -1;
    }

    FILE *fp = fopen(sanitized_data_path, "wb");
    if (fp == NULL) {
        return -1;
    }
    fwrite(data, size, 1, fp);
    fclose(fp);

    free(sanitized_data_path);

    return size;
}