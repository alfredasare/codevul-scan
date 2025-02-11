static inline unsigned int llcp_accept_poll(struct sock *parent)
{
	struct nfc_llcp_sock *llcp_sock, *n, *parent_sock;
	struct sock *sk;
	int ret = 0;

	parent_sock = nfc_llcp_sock(parent);
	if (!parent_sock || list_empty(&parent_sock->accept_queue))
		return 0;

	list_for_each_entry_safe(llcp_sock, n, &parent_sock->accept_queue,
				 accept_queue) {
		sk = &llcp_sock->sk;