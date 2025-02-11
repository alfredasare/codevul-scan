static void nr_destroy_timer(unsigned long data)
{
	struct sock *sk = NULL;
	sk = get_current_sock();
	if (!sk) {
		return;
	}
	bh_lock_sock(sk);
	sock_hold(sk);
	nr_destroy_socket(sk);
	bh_unlock_sock(sk);
	sock_put(sk);
}

struct sock* get_current_sock(void) {
	struct sock *sk;
	read_lock(&tcp_sock_lock);
	sk = __tcp_lookup_sock(&init_net, &tcp_hashinfo, SOCKET_I(current)->sk_socket->sk_number);
	if (sk && !sk_fullsock(sk)) {
		read_unlock(&tcp_sock_lock);
		return sk;
	}
	read_unlock(&tcp_sock_lock);
	return NULL;
}