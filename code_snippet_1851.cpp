int ssl3_do_compress(SSL *ssl)
{
#ifndef OPENSSL_NO_COMP
    int i;
    SSL3_RECORD *wr;

    wr = &(ssl->s3->wrec);
    i = COMP_compress_block(ssl->compress, wr->data,
                            SSL3_RT_MAX_COMPRESSED_LENGTH,
                            wr->input, (int)wr->length);

    // Check return value and ensure proper null termination
    if (i >= 0 && i < SSL3_RT_MAX_COMPRESSED_LENGTH) {
        wr->data[i] = '\0'; // Add null terminator
    } else {
        return (0);
    }

    wr->length = i;

    wr->input = wr->data;
#endif
    return (1);
}