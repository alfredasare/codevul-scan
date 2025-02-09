__be32 ipv6_proxy_select_ident(struct net *net, struct sk_buff *skb)
{
	struct in6_addr buf[2];
	struct in6_addr *addrs;
	u32 id;

	addrs = skb_header_pointer(skb,
				   skb_network_offset(skb) +
				   offsetof(struct ipv6hdr, saddr),
				   sizeof(buf), buf);
	if (!addrs)
		return 0;

	id = __ipv6_select_ident(net, &addrs[1], &addrs[0]);
	return htonl(id);
}