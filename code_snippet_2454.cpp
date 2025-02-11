static void rewind_dns_packet(DnsPacketRewinder *rewinder) {
    if (rewinder->packet && rewinder->saved_rindex < rewinder->packet->buffer_size) {
        dns_packet_rewind(rewinder->packet, rewinder->saved_rindex);
        rewinder->packet->buffer[rewinder->packet->buffer_size - 1] = '\0';
    }
}