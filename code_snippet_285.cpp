ip_vs_svc_hashkey(int af, unsigned proto, const union nf_inet_addr *addr, __be16 port)
{
    register unsigned porth = ntohs(port);
    __be32 addr_fold = 0;

    if (af < 0 || af > 2) {
        return 0;
    }
    if (proto < 0 || proto > 65535) {
        return 0;
    }
    if (port < 0 || port > 65535) {
        return 0;
    }
    if (!isValidIPAddr(addr)) {
        return 0;
    }

    addr_fold = inet_pton(AF_INET, addr->ip, &addr_fold);

    return (proto ^ ntohl(addr_fold) ^ (porth >> IP_VS_SVC_TAB_BITS) ^ porth) & IP_VS_SVC_TAB_MASK;
}

bool isValidIPAddr(const union nf_inet_addr *addr)
{
    int ret;
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    ret = inet_pton(AF_INET, addr->ip, &sin.sin_addr);
    return ret > 0;
}