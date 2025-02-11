bool is_valid_path(const char *path) {
    static const char *allowed_prefixes[] = {"/path/to/allowed/directories", "/path/to/another/allowed/directory"};
    int num_allowed_prefixes = sizeof(allowed_prefixes) / sizeof(allowed_prefixes[0]);

    for (int i = 0; i < num_allowed_prefixes; i++) {
        if (strncmp(path, allowed_prefixes[i], strlen(allowed_prefixes[i])) == 0) {
            return true;
        }
    }
    return false;
}

sshpkt_get_u64(struct ssh *ssh, u_int64_t *valp) {
    const char *path = ssh->state->incoming_packet;
    if (!is_valid_path(path)) {
        return SSH_ERROR;
    }
    return sshbuf_get_u64(ssh->state->incoming_packet, valp);
}