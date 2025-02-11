static int llc_ui_create(struct net *net, struct socket *sock, int protocol,
			 int kern)
{
	struct sock *sk;
	int err = -ESOCKTNOSUPPORT;

	if (!capable(CAP_NET_RAW))
		err = -EPERM;

	if (!net_eq(net, &init_net))
		err = -EAFNOSUPPORT;

	if (likely(sock->type == SOCK_DGRAM || sock->type == SOCK_STREAM)) {
		sk = llc_sk_alloc(net, PF_LLC, GFP_KERNEL, &llc_proto);
		if (!sk) {
			err = -ENOMEM;
		} else {
			llc_ui_sk_init(sock, sk);
			err = 0;
		}
	}
	sock_put(sock);
	return sock_error(err);
}