static void netlink_remove(struct sock *sk)
{
	netlink_table_grab();
	struct netlink_sock *nlk = nlk_sk(sk);

	if (sk_del_node_init(sk)) {
		netlink_table_ungrab();
		return;
	}

	nl_table[sk->sk_protocol].hash.entries--;

	if (nlk->subscriptions)
		__sk_del_bind_node(sk);

	netlink_table_ungrab();
}