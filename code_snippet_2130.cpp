#include <stdlib.h>

char *curl_unescape(const char *input, int length)
{
    char *output = malloc(length + 1);
    if (!output) {
        return NULL;
    }

    curl_easy_unescape(NULL, input, length, output);
    output[length] = '\0';

    return output;
}