#include <string.h>

#define MAX_NAME_LENGTH 32

check_variable_error_message(char *name)
{
    if (strlen(name) > MAX_NAME_LENGTH) {
        return;
    }

    if (strncmp(name, "acl_", 4) == 0) {
        char expanded_message[256];
        size_t required_size = snprintf(expanded_message, sizeof(expanded_message), "%s (%s)",
                                       expand_string_message,
                                       (name[4] == 'c' || name[4] == 'm') ?
                                       (isalpha(name[5]) ?
                                        "6th character of a user-defined ACL variable must be a digit or underscore" :
                                        "strict_acl_vars is set") :
                                       "user-defined ACL variables must start with acl_c or acl_m");

        if (required_size >= sizeof(expanded_message)) {
            return;
        }

        expand_string_message = expanded_message;
    }
}