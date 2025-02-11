#include <string.h>

static int cmd_mv(void *data, const char *input) {
    char cmd[256];
    memset(cmd, 0, sizeof(cmd));

    // Validate input and limit it to a safe size
    if (strlen(input) > sizeof(cmd)-2) {
        return 0;
    }

    // Properly validate and sanitize input before using it
    snprintf(cmd, sizeof(cmd), "mv %s", input);

    return r_syscmd_mv(cmd)? 1: 0;
}