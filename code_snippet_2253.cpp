int RSA_generate_key_ex(RSA *rsa, int bits, BIGNUM *e_value, BN_GENCB *cb)
{
    if (rsa->meth->rsa_keygen) {
        int ret = rsa->meth->rsa_keygen(rsa, bits, e_value, cb);
        if (ret <= 0) {
            /* Handle error and release resources */
            return ret;
        }
    } else {
        int ret = rsa_builtin_keygen(rsa, bits, e_value, cb);
        if (ret <= 0) {
            /* Handle error and release resources */
            return ret;
        }
    }
    return 1; /* Success */
}