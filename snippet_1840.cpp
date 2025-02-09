mux_client_request_stop_listening(int fd)
{
	Buffer m;
	char *e;
	u_int type, rid;

	debug3("%s: entering", __func__);

	buffer_init(&m);
	buffer_put_int(&m, MUX_C_STOP_LISTENING);
	buffer_put_int(&m, muxclient_request_id);

	if (mux_client_write_packet(fd, &m) != 0)
		fatal("%s: write packet: %s", __func__, strerror(errno));

	buffer_clear(&m);

	/* Read their reply */
	if (mux_client_read_packet(fd, &m) != 0)
		fatal("%s: read from master failed: %s",
		    __func__, strerror(errno));

	type = buffer_get_int(&m);
	if ((rid = buffer_get_int(&m)) != muxclient_request_id)
		fatal("%s: out of sequence reply: my id %u theirs %u",
		    __func__, muxclient_request_id, rid);
	switch (type) {
	case MUX_S_OK:
		break;
	case MUX_S_PERMISSION_DENIED:
		e = buffer_get_string(&m, NULL);
		fatal("Master refused stop listening request: %s", e);
	case MUX_S_FAILURE:
		e = buffer_get_string(&m, NULL);
		fatal("%s: stop listening request failed: %s", __func__, e);
	default:
		fatal("%s: unexpected response from master 0x%08x",
		    __func__, type);
	}
	buffer_free(&m);
	muxclient_request_id++;
}
