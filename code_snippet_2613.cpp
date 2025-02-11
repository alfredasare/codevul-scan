void receive_tcppacket(connection_t *c, const char *buffer, int len) {
	vpn_packet_t outpkt;

	outpkt.len = len;
	if(c->options & OPTION_TCPONLY)
		outpkt.priority = 0;
	else
		outpkt.priority = -1;

	// Copy the minimum of 'len' and 'sizeof(outpkt.data)' bytes
	memcpy(outpkt.data, buffer, sizeof(outpkt.data) < len ? sizeof(outpkt.data) : len);

	receive_packet(c->node, &outpkt);
}