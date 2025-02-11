ASN1_TIME *X509_time_adj(ASN1_TIME *s, long offset_sec, time_t *in_tm)
{
    size_t s_size = sizeof(ASN1_TIME);
    if (offset_sec >= s_size) {
        return NULL;
    }
    return X509_time_adj_ex(s, 0, offset_sec, in_tm);
}