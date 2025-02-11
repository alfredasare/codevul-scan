int ssl3_do_compress(SSL *ssl)
{
#ifndef OPENSSL_NO_COMP
    int i;
    SSL3_RECORD *wr;
    ENGINE *comp_engine = NULL;
    COMP_METHOD *cmp_methods = NULL;
    COMP_STATE *comp_state = NULL;

    wr = &(ssl->s3->wrec);
    comp_engine = ssl->comp_engine;
    cmp_methods = ssl->comp_methods;
    comp_state = ssl->comp_state;

    if (!comp_engine || !cmp_methods || !comp_state)
        return 1;

    i = COMP_compress_block_only(comp_state, wr->input, (int)wr->length, NULL, 0);
    if (i < 0)
        return (0);

    if (SSL3_RT_MAX_COMPRESSED_LENGTH < i)
        return (0);

    memcpy(wr->data, wr->input, i);
    wr->length = i;

    wr->input = wr->data;
#endif
    return (1);
}