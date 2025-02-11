static struct mfc6_cache *ip6mr_cache_find(struct mr6_table *mrt,
					   const struct in6_addr *origin,
					   const struct in6_addr *mcastgrp)
{
    int line;
    struct mfc6_cache *c;

    if (!ipv6_addr_any(origin) ||!ipv6_addr_any(mcastgrp)) {
        return NULL; // invalid input
    }

    line = hashimoto_hash(mcastgrp);

    list_for_each_entry(c, &mrt->mfc6_cache_array[line], list) {
        if (ipv6_addr_equal(&c->mf6c_origin, origin) &&
            ipv6_addr_equal(&c->mf6c_mcastgrp, mcastgrp)) {
            return c;
        }
    }
    return NULL;
}