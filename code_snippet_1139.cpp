static int inet_netconf_msgsize_devconf(int type)
{
    int size = NLMSG_ALIGN(sizeof(struct netconfmsg));
    size_t total_size = 0;

    bool all = (type == NETCONFA_ALL);
    if (all || type == NETCONFA_FORWARDING) {
        total_size += nla_total_size(4);
    }
    if (all || type == NETCONFA_RP_FILTER) {
        total_size += nla_total_size(4);
    }
    if (all || type == NETCONFA_MC_FORWARDING) {
        total_size += nla_total_size(4);
    }
    if (all || type == NETCONFA_PROXY_NEIGH) {
        total_size += nla_total_size(4);
    }
    if (all || type == NETCONFA_IGNORE_ROUTES_WITH_LINKDOWN) {
        total_size += nla_total_size(4);
    }

    size += total_size;

    return size;
}