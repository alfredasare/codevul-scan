static int rfcomm\_sock\_getname(struct socket \*sock, struct sockaddr \*addr, int \*len, int peer)
{
	struct sockaddr\_rc \*sa = NULL;
	struct sock *sk = sock->sk;

	BT\_DBG("sock %p, sk %p", sock, sk);

	if (peer && sk->sk\_state != BT\_CONNECTED &&
	sk->sk\_state != BT\_CONNECT && sk->sk\_state != BT\_CONNECT2)
		return -ENOTCONN;

	sa = kzalloc(sizeof(*sa), GFP\_KERNEL);
	if (!sa)
		return -ENOMEM;

	memcpy(sa, addr, min(*len, sizeof(*sa)));

	if (sa->sa\_family == AF\_BLUETOOTH) {
		sa->rc\_family  = AF\_BLUETOOTH;
		sa->rc\_channel = rfcomm\_pi(sk)->channel;
		if (peer)
			bacpy(&sa->rc\_bdaddr, &rfcomm\_pi(sk)->dst);
		else
			bacpy(&sa->rc\_bdaddr, &rfcomm\_pi(sk)->src);

		memcpy(addr, sa, min(*len, sizeof(*sa)));
		*len = sizeof(struct sockaddr\_rc);
	} else {
		kfree(sa);
		return -EINVAL;
	}

	kfree(sa);
	return 0;
}