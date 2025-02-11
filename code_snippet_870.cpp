ASN1_TIME *X509_time_adj(ASN1_TIME *s, long offset_sec, time_t *in_tm)
{
    if (offset_sec > INT_MAX - ASN1_TIME_gmtoff(s)) {
        /* Handle error condition */
    }
    return X509_time_adj_ex(s, 0, offset_sec, in_tm);
}