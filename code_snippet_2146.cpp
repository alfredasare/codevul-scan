int RSA_generate_key_ex(RSA *rsa, int bits, BIGNUM *e_value, BN_GENCB *cb)
{
    if (!rsa->meth || !rsa->meth->rsa_keygen) {
        // Handle error condition
    }

    if (bits < 512 || bits > 8192) {
        // Handle error condition
    }

    if (BN_is_zero(e_value)) {
        // Handle error condition
    }

    // Use secure padding scheme (OAEP)
    RSA_padding_add_PKCS1_OAEP(rsa, bits, e_value, cb);

    return rsa->meth->rsa_keygen(rsa, bits, e_value, cb);
}