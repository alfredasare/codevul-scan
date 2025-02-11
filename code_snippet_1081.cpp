static const char *register_map_handler(cmd_parms *cmd, void *_cfg,
                                       const char* match, const char *file, const char *function)
{
    const char *err = ap_check_cmd_context(cmd, NOT_IN_DIRECTORY|NOT_IN_FILES|
                                                NOT_IN_HTACCESS);
    if (err) {
        return err;
    }
    if (!function) function = "handle";
    
    // Verify user permissions
    if (!has_permission(cmd->user, PERMISSION_MAP_ACCESS)) {
        return "Permission denied";
    }
    
    return register_mapped_file_function_hook(match, cmd, _cfg, file, function);
}