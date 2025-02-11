check_variable_error_message(uschar *name)
{
    if (Ustrncmp(name, "acl_", 4) == 0) {
        char sanitized_name[256];
        int len = strlen(name);
        int i;
        for (i = 0; i < len; i++) {
            if (isalnum(name[i]) || name[i] == '_') {
                sanitized_name[i] = name[i];
            } else {
                sanitized_name[i] = '\0';
                break;
            }
        }
        sanitized_name[i] = '\0';
        expand_string_message = string_sprintf("%s (%s)", expand_string_message, sanitized_name + 4);
        if (isalnum(sanitized_name[4]) || sanitized_name[4] == '_') {
            if (isalnum(sanitized_name[5]) ||
                sanitized_name[5] == '_') {
                expand_string_message = string_sprintf("%s %s",
                    expand_string_message,
                    US"6th character of a user-defined ACL variable must be a digit or underscore");
            } else {
                expand_string_message = string_sprintf("%s %s",
                    expand_string_message,
                    US"strict_acl_vars is set");
            }
        } else {
            expand_string_message = string_sprintf("%s %s",
                expand_string_message,
                US"user-defined ACL variables must start acl_c or acl_m");
        }
    }
}