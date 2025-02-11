lrmd_tls_server_key_cb(gnutls_session_t session, const char *username, gnutls_datum_t *key)
{
    // Validate the username
    if (strchr(username, '/')!= NULL || strlen(username) > 20) {
        return GNUTLS_E_INVALID_REQUEST;
    }

    // Restrict the allowed directories and files
    const char *allowed_dirs[] = {"/path/to/allowed/directory", "allowed_file.txt"};
    int allowed_dir_count = sizeof(allowed_dirs) / sizeof(*allowed_dirs);

    for (int i = 0; i < allowed_dir_count; i++) {
        if (strcmp(username, allowed_dirs[i]) == 0) {
            return lrmd_tls_set_key(key);
        }
    }

    return GNUTLS_E_ACCESS_DENIED;
}