void receive_tcppacket(connection_t *c, const char *buffer, int len) {
    vpn_packet_t outpkt;
    size_t outpkt_size = sizeof(outpkt.data);

    if (len > outpkt_size) {
        // Handle error or truncate the buffer
    }

    outpkt.len = len;
    if (c->options & OPTION_TCPONLY)
        outpkt.priority = 0;
    else
        outpkt.priority = -1;

    memcpy_s(outpkt.data, outpkt_size, buffer, len);

    receive_packet(c->node, &outpkt);
}