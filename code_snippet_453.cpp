sshpkt_get_u64(struct ssh *ssh, u_int64_t *valp)
{
    // Check if ssh->state->incoming_packet and its data are not NULL
    if (ssh->state->incoming_packet == NULL || ssh->state->incoming_packet->data == NULL) {
        return -1;
    }

    // Check if input data is within expected buffer size
    if (sshbuf_len(ssh->state->incoming_packet) < sizeof(*valp)) {
        return -1;
    }

    // Get u_int64_t value from buffer
    return sshbuf_get_u64(ssh->state->incoming_packet, valp);
}