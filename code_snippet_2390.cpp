static int call_usermodehelper_keys(char *path, char **argv, char **envp, 
				   struct key *session_keyring, int wait)
{
    struct subprocess_info *info;
    size_t path_len, argv_len, envp_len;

    // Validate input parameters
    if (!path || !argv || !envp) {
        return -EINVAL;
    }

    // Calculate the length of the input data
    path_len = strlen(path);
    argv_len = 0;
    while (*argv) {
        argv_len += strlen(*argv) + 1;
        argv++;
    }
    envp_len = 0;
    while (*envp) {
        envp_len += strlen(*envp) + 1;
        envp++;
    }

    // Allocate a new buffer for the sanitized input data
    char *sanitized_path = malloc(path_len + 1);
    char *sanitized_argv = malloc(argv_len + 1);
    char *sanitized_envp = malloc(envp_len + 1);

    // Sanitize the input data
    strncpy(sanitized_path, path, path_len);
    sanitized_path[path_len] = '\0';
    char *tmp_argv = sanitized_argv;
    while (*argv) {
        strncpy(tmp_argv, *argv, strlen(*argv) + 1);
        tmp_argv += strlen(*argv) + 1;
        argv++;
    }
    char *tmp_envp = sanitized_envp;
    while (*envp) {
        strncpy(tmp_envp, *envp, strlen(*envp) + 1);
        tmp_envp += strlen(*envp) + 1;
        envp++;
    }

    // Call the helper function with sanitized input data
    info = call_usermodehelper_setup(sanitized_path, sanitized_argv, sanitized_envp, GFP_KERNEL, umh_keys_init, umh_keys_cleanup, session_keyring);
    if (!info)
        return -ENOMEM;

    key_get(session_keyring);
    return call_usermodehelper_exec(info, wait);
}