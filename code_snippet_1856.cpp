cifs_reclassify_socket4(struct socket *sock)
{
	struct sock *sk = sock->sk;
	BUG_ON(sock_owned_by_user(sk));

	/* Validate the user-supplied data (sock) */
	if (!sk || strlen(sk->sk_data.s_rcvbuf) > MAX_NAME_LENGTH) {
		pr_err("Invalid socket name or length\n");