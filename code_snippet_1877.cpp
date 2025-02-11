static int ssl3_add_cert_to_buf(BUF_MEM *buf, unsigned long *l, X509 *x)
{
    int n;
    unsigned char *p;

    n = X509_size(x);
    if (n > (*l) + 3) {
        SSLerr(SSL_F_SSL3_ADD_CERT_TO_BUF, ERR_R_BUF_LIB);
        return (-1);
    }

    p = (unsigned char *)&(buf->data[*l]);
    i2d_X509(x, &p);
    *l += n + 3;

    return (0);
}