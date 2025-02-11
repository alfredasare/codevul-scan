void SSL3_RECORD_clear(SSL3_RECORD *r, size_t num_recs)
{
    size_t i;

    for (i = 0; i < num_recs; i++) {
        SSL3_RECORD *rec = &r[i];
        memset(rec, 0, sizeof(*rec));
    }
}