static inline __be32 try_6rd(struct ip_tunnel *tunnel, const struct in6_addr *v6dst)
{
	__be32 dst = 0;
	const __be3