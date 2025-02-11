SMBencrypt(unsigned char *passwd, const unsigned char *c8, unsigned char *p24, size_t passwd_len)
{
	int rc;
	unsigned char p14[14], p16[16], p21[21];

	memset(p14, '\0', 14);
	memset(p16, '\0', 16);
	memset(p21, '\0', 21);

	if (passwd_len > sizeof(p14)) {
		return E_INVALID_PASSWD_LEN;
	}

	memcpy(p14, passwd, passwd_len);
	rc = E_P16(p14, p16);
	if (rc)
		return rc;

	memcpy(p21, p16, sizeof(p21));
	rc = E_P24(p21, c8, p24);

	return rc;
}