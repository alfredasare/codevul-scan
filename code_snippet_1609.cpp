static struct mfc6_cache *ip6mr_cache_find(struct mr6_table *mrt,
					   const struct in6_addr *origin,
					   const struct in6_addr *mcastgrp)
{
	u_int32_t hash;
	int line;
	struct mfc6_cache *c;

	hash = jhash_3words(origin->s6_addr32, mcastgrp->s6_addr32, 0, 0);
	line = hash % MFC6_CACHE_HASH_SIZE;

	if (line < 0 || line >= MFC6_CACHE_HASH_SIZE)
		return NULL;

	list_for_each_entry(c, &mrt->mfc6_cache_array[line], list) {
		if (ipv6_addr_equal(&c->mf6c_origin, origin) &&
		    ipv6_addr_equal(&c->mf6c_mcastgrp, mcastgrp))