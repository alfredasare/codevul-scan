#include <string.h> /* for strnlen() */

#define MAX_LEN 64 /* Define the maximum allowed length for the string */

void cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item) {
    if (!item) return;

    // Validate input length
    if (strnlen(string, MAX_LEN) >= MAX_LEN) {
        // Handle error or return error code
        return;
    }

    if (item->string) cJSON_free(item->string);
    item->string = cJSON_strdup(string);
    cJSON_AddItemToArray(object, item);
}