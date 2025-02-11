void SSL3_RECORD_clear(SSL3_RECORD *r, size_t num_recs)
{
    if (r != NULL && num_recs > 0 && num_recs <= SSL3_NUM_RECORD_CTX) {
        for (size_t i = 0; i < num_recs; i++) {
            memset(&r[i], 0, sizeof(SSL3_RECORD));
            r[i].comp = calloc(1, SSL3_RT_MAX_COMPRESSED_LEN);
            if (r[i].comp == NULL) {
                /* Handle error */
            }
        }
    }
}