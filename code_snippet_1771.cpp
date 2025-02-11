static void ssl_update_checksum_start(ssl_context *ssl, unsigned char *buf, size_t len)
{
    if (len > SSL_MAX_BUFFER_SIZE) {
        /* Handle error or sanitize input */
    }

    if (len > sizeof(ssl->handshake->fin_md5.hash)) {
        /* Handle error or truncate the data */
    }

    memcpy(ssl->handshake->fin_md5.hash, buf, len);
    ssl->handshake->fin_md5.len = len;
    md5_finish(&ssl->handshake->fin_md5);

    memcpy(ssl->handshake->fin_sha1.hash, buf, len);
    ssl->handshake->fin_sha1.len = len;
    sha1_finish(&ssl->handshake->fin_sha1);

    memcpy(ssl->handshake->fin_sha2.hash, buf, len);
    ssl->handshake->fin_sha2.len = len;
    sha2_finish(&ssl->handshake->fin_sha2);

#if defined(POLARSSL_SHA4_C)
    memcpy(ssl->handshake->fin_sha4.hash, buf, len);
    ssl->handshake->fin_sha4.len = len;
    sha4_finish(&ssl->handshake->fin_sha4);
#endif
}