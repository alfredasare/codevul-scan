#include <string.h>

#define MAX_NID_LENGTH 6

// ...

void format_nid(const u_char *data)
{
    // Validate input data length
    if (data == NULL || *data == '\0' || strlen((const char *)data) > MAX_NID_LENGTH) {
        return "";
    }

    static char buf[4][sizeof("01:01:01:01")];
    static int i = 0;
    i = (i + 1) % 4;

    // Use strncpy to safely copy input data
    strncpy(buf[i], (const char *)data, sizeof(buf[i]));
    buf[i][sizeof(buf[i]) - 1] = '\0'; // Ensure null termination

    // Format the string using snprintf
    snprintf(buf[i], sizeof(buf[i]), "%02x:%02x:%02x:%02x",
             data[0], data[1], data[2], data[3]);
    return buf[i];
}