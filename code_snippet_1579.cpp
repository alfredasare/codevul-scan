static void llc_ui_sk_init(struct socket *sock, struct sock *sk)
{
	if (!sock || !sock->ops) {
		pr_err("Invalid socket or socket operations\n");
		return;
	}

	sock_graft(sk, sock);
	sk->sk_type	= sock->type;
	sock_assign_operations(sock, &llc_ui_ops);
}