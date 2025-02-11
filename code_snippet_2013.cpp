static int ssl3_add_cert_to_buf(BUF_MEM *buf, unsigned long *l, X509 *x)
{
	int n;
	unsigned char *p;

	n = i2d_X509(x, NULL);
	if (!BUF_MEM_grow_clean(buf, (int)(n + (*l) + 3)))
	{
		SSLerr(SSL_F_SSL3_ADD_CERT_TO_BUF, ERR_R_BUF_LIB);
		return(-1);
	}
	p = (unsigned char *)&(buf->data[*l]);
	*p = (unsigned char)n;
	*(p + 1) = (unsigned char)(n >> 8);
	*(p + 2) = (unsigned char)(n >> 16);
	p += 3;
	memcpy(p, X509_get0_notBefore(x)->data, X509_not_before_length());
	p += X509_not_before_length();
	memcpy(p, X509_get0_notAfter(x)->data, X509_not_after_length());
	p += X509_not_after_length();
	memcpy(p, x->cert_info, i2d_X509_length(x));

	*l += n + 3 + X509_not_before_length() + X509_not_after_length() + i2d_X509_length(x);

	return(0);
}