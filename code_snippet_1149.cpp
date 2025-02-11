static int pvc_create(struct net *net, struct socket *sock, int protocol,
		      int kern)
{
	if (net!= &init_net)
		return -EAFNOSUPPORT;

	if (protocol < 0 || protocol >= IPPROTO_MAX) {
		return -EINVAL; /* invalid protocol number */
	}

	// whitelist allowed protocols
	static const int allowed_protocols[] = { SOCK_STREAM, SOCK_DGRAM, SOCK_RAW };
	for (int i = 0; i < ARRAY_SIZE(allowed_protocols); i++) {
		if (protocol == allowed_protocols[i]) {
			break;
		}
	}

	if (i == ARRAY_SIZE(allowed_protocols)) {
		return -EPROTONOSUPPORT; /* unsupported protocol */
	}

	sock->ops = &pvc_proto_ops;
	return vcc_create(net, sock, protocol, PF_ATMPVC);
}