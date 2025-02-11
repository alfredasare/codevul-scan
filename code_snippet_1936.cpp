static int ssl23_no_ssl2_ciphers(SSL *s)
{
    SSL_CIPHER *cipher;
    STACK_OF(SSL_CIPHER) *ciphers;
    int i;
    ciphers = SSL_get_ciphers(s);
    for (i = 0; i < sk_SSL_CIPHER_num(ciphers); i++)
    {
        cipher = sk_SSL_CIPHER_value(ciphers, i);
        if (cipher->algorithm_bitlen < 128)
            return