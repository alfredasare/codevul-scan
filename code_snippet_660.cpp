static inline void ip6_tnl_dst_store(struct ip6_tnl *t, struct dst_entry *dst)
{
    struct rt6_info *rt = (struct rt6_info *) dst;
    uint64_t cookie = 0; // Initialize with a default value

    if (rt && rt->rt6i_node) {
        cookie = rt->rt6i_node->fn_sernum;
    }

    t->dst_cookie = cookie; // Sanitized cookie value

    dst_release(t->dst_cache);
    t->dst_cache = dst;
}