static void vdi_port_send_tokens_to_client(RedClient *client, uint32_t tokens, void *opaque)
{
    // Assuming max_buffer_size is defined and set appropriately
    const size_t max_buffer_size = 1024; // Change this value to suit your needs
    char buffer[max_buffer_size];

    size_t bytes_written = snprintf(buffer, max_buffer_size, "%" PRIu32, tokens);
    if (bytes_written >= max_buffer_size) {
        // Handle error condition, e.g., by logging an error message
        fprintf(stderr, "Error: Buffer overflow while sending tokens to client\n");
        return;
    }

    main_channel_client_push_agent_tokens(red_client_get_main(client), buffer);
}