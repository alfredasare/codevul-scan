static inline void sctp_copy_descendant(struct sock *sk_to, const struct sock *sk_from)
{
	int ancestor_size = sizeof(struct inet_sock) +
			    sizeof(struct sctp_sock) -
			    offsetof(struct sctp_sock, auto_asconf_list);

	if (sk_from->sk_family == PF_INET6)
		ancestor_size += sizeof(struct ipv6_pinfo);

        if (ancestor_size > sk_to->sk_allocation) {
                /* Handle error, e.g. return an error code or log an error message */
                return;
        }

	__inet_sk_copy_descendant(sk_to, sk_from, ancestor_size);
}