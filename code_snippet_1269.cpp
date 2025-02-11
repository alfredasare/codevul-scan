#define MAX_MATCH_LENGTH 256 // Adjust this value based on your buffer size

static const char *register_map_handler(cmd_parms *cmd, void *_cfg,
                                       const char* match, const char *file, const char *function)
{
    // Check if the length of match is within the allowed limit
    if (strlen(match) >= MAX_MATCH_LENGTH) {
        return "Error: Input string is too long";
    }

    const char *err = ap_check_cmd_context(cmd, NOT_IN_DIRECTORY|NOT_IN_FILES|NOT_IN_HTACCESS);
    if (err) {
        return err;
    }
    if (!function) function = "handle";

    // Use strncpy instead of strcpy to prevent buffer overflows
    return register_mapped_file_function_hook(strncpy(malloc(MAX_MATCH_LENGTH), match, MAX_MATCH_LENGTH - 1), cmd, _cfg, file, function);
}