#include <string.h>

#define MAX_FUNCTION_FLAG_LENGTH 15

static bool isFunctionFlag(const char *n) {
    // Check if the input string is within the maximum allowed length
    if (strnlen(n, MAX_FUNCTION_FLAG_LENGTH) >= MAX_FUNCTION_FLAG_LENGTH) {
        return false;
    }

    // Perform the string comparisons safely
    return (!strncmp (n, "sym.func.", 9)
    || !strncmp (n, "method.", 7)
    || !strncmp (n, "sym.", 5)
    || !strncmp (n, "func.", 5)
    || !strncmp (n, "fcn.0", 5));
}