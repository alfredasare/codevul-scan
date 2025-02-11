int exsltCryptoGcryptHash(xmlXPathParserContextPtr ctxt ATTRIBUTE_UNUSED, int algorithm, const char *msg, unsigned long msglen, char dest[HASH_DIGEST_LENGTH]) {
    exsltCryptoGcryptInit();
    size_t required_size = gcry_md_get_algo_dlen(algorithm);

    if (required_size > sizeof(dest)) {
        return -1;
    }

    gcry_md_hash_buffer(algorithm, dest, msg, msglen);
    return 0;
}