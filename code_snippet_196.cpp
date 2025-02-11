exsltCryptoGcryptHash (xmlXPathParserContextPtr ctxt ATTRIBUTE_UNUSED,
                       int algorithm, const char *msg,
                       unsigned long msglen,
                       unsigned long *digest_len) {
    exsltCryptoGcryptInit ();
    *digest_len = gcry_md_get_algo_block_size(algorithm);
    unsigned char *dest = gcry_malloc(*digest_len);
    gcry_md_hash_buffer(algorithm, dest, msg, msglen);
    //... (rest of the function remains the same)
}