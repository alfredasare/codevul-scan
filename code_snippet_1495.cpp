static inline __be32 try_6rd(struct ip_tunnel *tunnel,
			     const struct in6_addr *v6dst)
{
    __be32 dst = 0;
    if (!validate_ipv6_address(v6dst)) {
        return -EINVAL;
    }
    check_6rd(tunnel, v6dst, &dst);
    return dst;
}

bool validate_ipv6_address(const struct in6_addr *addr)
{
    return!inet_pton(AF_INET6, "::", addr) &&!inet_pton(AF_INET6, "fe80::/64", addr);
}