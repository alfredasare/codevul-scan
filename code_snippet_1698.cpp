static void s_wrpkt(Ssh ssh, struct Packet *pkt) {
    int len, backlog, offset;
    len = s_wrpkt_prepare(ssh, pkt, &offset);

    // Validate and sanitize the offset
    if (offset < 0 || offset > SSH_MAX_PACKET_SIZE) {
        ssh_error(ssh, SSH_ERROR_INVALID_PACKET, "Invalid packet offset");
        return;
    }

    // Use a whitelist approach to restrict the allowed offset values
    if (!is_valid_offset(offset)) {
        ssh_error(ssh, SSH_ERROR_INVALID_PACKET, "Invalid packet offset");
        return;
    }

    backlog = s_write(ssh, pkt->data + offset, len);
    if (backlog > SSH_MAX_BACKLOG)
        ssh_throttle_all(ssh, 1, backlog);

    ssh_free_packet(pkt);
}

bool is_valid_offset(int offset) {
    return offset >= 0 && offset <= SSH_MAX_PACKET_SIZE;
}