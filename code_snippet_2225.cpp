static inline void mcryptd_check_internal(struct rtattr **tb, u32 *type,
					  u32 *mask)
{
	const struct crypto_attr_type *algt;

	algt = crypto_get_attr_type_const(tb);
	if (!algt)
		return;
	if (algt->type & CRYPTO_ALG_INTERNAL)
		*type |= CRYPTO_ALG_INTERNAL;
	if (algt->mask & CRYPTO_ALG_INTERNAL)
		*mask |= CRYPTO_ALG_INTERNAL;
}