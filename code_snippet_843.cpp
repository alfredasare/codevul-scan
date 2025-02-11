static void DSA_get0_key(const DSA *d, const BIGNUM **pub_key, const BIGNUM **priv_key)
{
    if (d == NULL || d->pub_key == NULL || d->priv_key == NULL) {
        *pub_key = NULL;
        *priv_key = NULL;
        return;
    }

    if (sizeof(BIGNUM) > sizeof(**pub_key)) {
        *pub_key = NULL;
        *priv_key = NULL;
        return;
    }

    *pub_key = d->pub_key;
    *priv_key = d->priv_key;
}