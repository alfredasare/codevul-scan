void tcp_packet_send(struct tcp_conn_t *conn, struct http_packet_t *pkt)
{
	size_t remaining = pkt->filled_size;
	size_t total = 0;
	while (remaining > 0) {
		ssize_t sent = send(conn->sd, pkt->buffer + total,
		                    remaining, MSG_NOSIGNAL);
		if (sent < 0) {
			if (errno == EPIPE) {
				conn->is_closed = 1;
				return;
			}
			ERR_AND_EXIT("Failed to sent data over TCP");
		}

		size_t sent_ulong = (unsigned) sent;
		total += sent_ulong;
		if (sent_ulong >= remaining)
			remaining = 0;
		else
			remaining -= sent_ulong;
	}
	NOTE("TCP: sent %lu bytes", total);
 }
