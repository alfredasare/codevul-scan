static int hidp_sock_release(struct socket *sock)
{
	struct sock *sk;

	BT_DBG("sock %p", sock);

	if (!sock) {
		pr_warn("Null socket passed to hidp_sock_release\n");
		return -EINVAL;
	}

	sk = sock->sk;

	if (!sk)
		return 0;

	bt_sock_unlink(&hidp_sk_list, sk);

	sock_orphan(sk);
	sock_put(sk);

	return 0;
}