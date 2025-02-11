void tipc_socket_stop(void)
{
	if (!sockets_enabled)
		return;

	sockets_enabled = 0;
	if (sock_unregister(tipc_family_ops.family) != 0) {
		pr_err("Failed to unregister socket family\n");
		// Handle failure as appropriate
	}
	if (proto_unregister(&tipc_proto) != 0) {
		pr_err("Failed to unregister protocol\n");
		// Handle failure as appropriate
	}
}