int DH_compute_key_padded(unsigned char *key, size_t key_size, const BIGNUM *pub_key, DH *dh)
{
    int rv, pad;
    rv = dh->meth->compute_key(key, pub_key, dh);
    if (rv <= 0)
        return rv;

    pad = BN_num_bytes(dh->p) - rv;
    if (pad > 0 && key_size >= rv + pad) {
        memmove(key + pad, key, rv);
        memset(key, 0, pad);
    } else {
        return -1;
    }

    return rv + pad;
}