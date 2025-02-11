static inline void mcryptd_check_internal(struct rtattr **tb, u32 *type, u32 *mask)
{
    struct crypto_attr_type *algt;

    algt = crypto_get_attr_type(tb);
    if (IS_ERR(algt)) {
        return;
    }

    if (algt != NULL) {
        if ((algt->type & CRYPTO_ALG_INTERNAL))
            *type |= CRYPTO_ALG_INTERNAL;
        if ((algt->mask & CRYPTO_ALG_INTERNAL))
            *mask |= CRYPTO_ALG_INTERNAL;
    }
}