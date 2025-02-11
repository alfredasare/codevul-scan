#include <limits.h> /* For INT_MIN and INT_MAX */

static int get_int_option(const char* options, const char* option_name,
                          int base, int default_value)
{
    const char* p = get_option(options, option_name);
    long int result;
    char *endptr;

    if (p == NULL)
        return default_value;

    result = strtol(p, &endptr, base);

    // Check for overflow and underflow
    if ((result == LONG_MIN && errno == ERANGE && *endptr != '\0') ||
        (result == LONG_MAX && errno == ERANGE && *endptr != '\0')) {
        return default_value;
    }

    // Ensure the result fits in an integer
    if (result < INT_MIN || result > INT_MAX) {
        return default_value;
    }

    return (int)result;
}