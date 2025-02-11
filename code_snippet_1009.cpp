static int hci_sock_getname(struct socket *sock, struct sockaddr *addr,
			    int *addr_len, int peer)
{
	struct sockaddr_hci *haddr = (struct sockaddr_hci *) addr;
	struct sock *sk = sock->sk;
	struct hci_dev *hdev = hci_pi(sk)->hdev;

	BT_DBG("sock %p sk %p", sock, sk);

	if (!hdev)
		return -EBADFD;

	lock_sock(sk);

	if (*addr_len >= sizeof(*haddr)) {
		*addr_len = sizeof(*haddr);
		haddr->hci_family = AF_BLUETOOTH;
		haddr->hci_dev    = hdev->id;
	} else {
		release_sock(sk);
		return -EINVAL;
	}

	release_sock(sk);
	return 0;
}