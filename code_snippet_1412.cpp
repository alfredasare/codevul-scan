static int sctp_bindx_add(struct sock *sk, struct sockaddr *addrs, int addrcnt)
{
	int cnt;
	int retval = 0;
	void *addr_buf;
	struct sockaddr *sa_addr;
	struct sctp_af *af;

	pr\_debug("%s: sk:%p, addrs:%p, addrcnt:%d\n", __func__, sk,
		 addrs, addrcnt);

	if (addrcnt <= 0 || addrs == NULL) {
		retval = -EINVAL;
		goto err_bindx_add;
	}

	addr\_buf = addrs;
	for (cnt = 0; cnt < addrcnt; cnt++) {
		/* The list may contain either IPv4 or IPv6 address;
		 * determine the address length for walking thru the list.
		 */
		sa\_addr = addr\_buf;
		af = sctp\_get\_af\_specific(sa\_addr->sa\_family);
		if (!af) {
			retval = -EINVAL;
			goto err_bindx_add;
		}

		if ((sa\_addr + 1) > ((char *)addr\_buf + addrcnt \* af->sockaddr\_len)) {
			retval = -EINVAL;
			goto err_bindx_add;
		}

		retval = sctp\_do\_bind(sk, (union sctp\_addr *)sa\_addr,
				      af->sockaddr\_len);

		addr\_buf += af->sockaddr\_len;

err\_bindx\_add:
		if (retval < 0) {
			/* Failed. Cleanup the ones that have been added */
			if (cnt > 0)
				sctp\_bindx\_rem(sk, addrs, cnt);
			return retval;
		}
	}

	return retval;
}