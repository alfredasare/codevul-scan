static int listen(struct socket *sock, int len)
{
	struct sock *sk = sock->sk;
	int res;

	if (sock->state != SS_UNCONNECTED || len < 0 || len > SOMAXCONN)
		return -EINVAL;

	lock_sock(sk);

	sock->state = SS_LISTENING;
	res = 0;

	release_sock(sk);
	return res;
}