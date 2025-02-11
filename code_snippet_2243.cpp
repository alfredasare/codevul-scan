int DH_compute_key_padded(unsigned char *key, const BIGNUM *pub_key, DH *dh)
{
    int rv, pad;
    rv = dh->meth->compute_key(key, pub_key, dh);
    if (rv <= 0)
        return rv;
    unsigned char random_pad[BN_num_bytes(dh->p)];
    if (!RAND_bytes(random_pad, BN_num_bytes(dh->p)))
        return -1; // error handling
    pad = BN_num_bytes(dh->p) - rv;
    if (pad > 0) {
        memmove(key + pad, key, rv);
        memset(key + pad, random_pad[0], pad);
    }
    return rv + pad;
}