static void handle_binary_protocol_error(conn *c) {
    write_bin_error(c, PROTOCOL_BINARY_RESPONSE_EINVAL, NULL, 0);
    if (settings.verbose) {
        if ((c->binary_header.request.opcode >= PROTOCOL_BINARY_OPCODE_MIN) &&
            (c->binary_header.request.opcode <= PROTOCOL_BINARY_OPCODE_MAX)) {
            fprintf(stderr, "Protocol error (opcode %02x), close connection %d\n",
                    c->binary_header.request.opcode, c->sfd);
        } else {
            // Handle invalid opcode error
        }
    }
    c->write_and_go = conn_closing;
}