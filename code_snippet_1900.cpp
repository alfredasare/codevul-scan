struct rtadv_prefix *rprefix;

rprefix = rtadv_prefix_lookup(rplist, p);
if (!rprefix) {
    rprefix = calloc(1, sizeof(struct rtadv_prefix));
    if (!rprefix) {
        return NULL;
    }
    memcpy(&rprefix->prefix, p, sizeof(struct prefix_ipv6));
    listnode_add(rplist, rprefix);
}
return rprefix;