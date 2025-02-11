static int lua_ap_get_active_config(lua_State *L) {
    //...
    for (subdir = dir->first_child; subdir; subdir = subdir->next) {
        if (ap_strcasecmp_match(subdir->directive, "servername") &&
              !ap_strcasecmp_match(validate_input(r->hostname, subdir->args, AP_ALLOWED_SERVERNAME_CHARS), subdir->args)) {
            read_cfg_tree(L, r, dir->first_child);
            return 1;
        }
        if (ap_strcasecmp_match(subdir->directive, "serveralias") &&
              !ap_strcasecmp_match(validate_input(r->hostname, subdir->args, AP_ALLOWED_SERVERALIAS_CHARS), subdir->args)) {
            read_cfg_tree(L, r, dir->first_child);
            return 1;
        }
    }
    return 0;
}

const char *AP_ALLOWED_SERVERNAME_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-";
const char *AP_ALLOWED_SERVERALIAS_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_";

char *validate_input(const char *input, const char *allowed_chars) {
    char *output = NULL;
    size_t output_len = 0;
    size_t input_len = strlen(input);

    for (size_t i = 0; i < input_len; i++) {
        if (strchr(allowed_chars, input[i])!= NULL) {
            output = realloc(output, output_len + 2);
            output[output_len++] = input[i];
            output[output_len] = '\0';
        }
    }
    return output;
}