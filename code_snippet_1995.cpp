PHPAPI int php_raw_url_decode(char *str, int len)
{
	char *dest = str;
	char *data = str;
	int safe_len = len;

	while (safe_len--) {
		if (*data == '%' && safe_len >= 2 && isxdigit((int) *(data + 1)) 
			&& isxdigit((int) *(data + 2))) {
#ifndef CHARSET_EBCDIC
			*dest = (char) php_htoi(data + 1);
#else
			*dest = os_toebcdic[(char) php_htoi(data + 1)];
#endif
			data += 2;
			safe_len -= 2;
		} else {
			*dest = *data;
		}
		data++;
		dest++;
	}
	*dest = '\0';
	return dest - str;
}