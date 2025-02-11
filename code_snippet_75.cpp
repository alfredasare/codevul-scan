static void vdi_port_send_tokens_to_client(RedClient *client, uint32_t tokens, void *opaque)
{
    char* sanitized_path = sanitize_path(red_client_get_main(client));
    if (sanitized_path) {
        main_channel_client_push_agent_tokens(sanitized_path, tokens);
        free(sanitized_path);
    }
}

char* sanitize_path(const char* path)
{
    static const char* allowed_directories[] = {"/path/to/allowed/directory1", "/path/to/allowed/directory2"};
    for (size_t i = 0; i < sizeof(allowed_directories) / sizeof(allowed_directories[0]); i++) {
        if (strncmp(path, allowed_directories[i], strlen(allowed_directories[i])) == 0) {
            return strdup(path);
        }
    }
    return NULL;
}