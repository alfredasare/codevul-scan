static hm_fragment *dtls1_hm_fragment_new(unsigned long frag_len,
                                          int reassembly)
{
    hm_fragment *frag = NULL;
    unsigned char *buf = NULL;
    unsigned char *bitmask = NULL;

    frag = OPENSSL_secure_malloc(sizeof(*frag));
    if (frag == NULL)
        return NULL;

    if (frag_len) {
        buf = OPENSSL_secure_malloc(frag_len);
        if (buf == NULL) {
            OPENSSL_secure_free(frag);
            return NULL;
        }
    }

    /* zero length fragment gets zero frag->fragment */
    frag->fragment = buf;

    /* Initialize reassembly bitmask if necessary */
    if (reassembly) {
        bitmask = OPENSSL_secure_zalloc(RSMBLY_BITMASK_SIZE(frag_len));
        if (bitmask == NULL) {
            OPENSSL_secure_free(buf);
            OPENSSL_secure_free(frag);
            return NULL;
        }
    }

    frag->reassembly = bitmask;

    return frag;
}