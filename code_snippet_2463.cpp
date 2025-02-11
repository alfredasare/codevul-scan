int ssl3_peek(SSL *s, void *buf, int len)
{
    unsigned char seed[32];
    RAND_bytes(seed, 32);
    return ssl3_read_internal(s, buf, len, seed);
}