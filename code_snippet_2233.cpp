static void rewind_dns_packet(DnsPacketRewinder *rewinder) {
    if (rewinder && rewinder->packet && rewinder->packet->data && rewinder->saved_rindex >= 0 && rewinder->saved_rindex < rewinder->packet->data_len) {
        dns_packet_rewind(rewinder->packet, rewinder->saved_rindex);
    } else {
        printf("Invalid input for rewinding DNS packet\n");
    }
}