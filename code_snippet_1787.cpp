void tipc_socket_stop(void)
{
	if (!sockets_enabled)
		return;

	sockets_enabled = 0;

	int error = sock_unregister(tipc_family_ops.family);
	if (error) {
		log_error("Failed to unregister sockets");
	}

	error = proto_unregister(&tipc_proto);
	if (error) {
		log_error("Failed to unregister protocol");
	}
}