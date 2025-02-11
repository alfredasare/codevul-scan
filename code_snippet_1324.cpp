static int pvc_create(struct net *net, struct socket *sock, int protocol, int kern)
{
	if (net != &init_net || protocol < 0 || protocol > 255)
		return -EAFNOSUPPORT;

	sock->ops = &pvc_proto_ops;
	return vcc_create(net, sock, protocol, PF_ATMPVC);
}