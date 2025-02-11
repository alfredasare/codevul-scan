static zend_string *get_http_headers(php_stream *stream)
{
	smart_str tmp_response = {0};
	char headerbuf[8192];
	size_t n;

	while (php_stream_gets(stream, headerbuf, sizeof(headerbuf))) {
		if ((headerbuf[0] == '\r' && headerbuf[1] == '\n') ||
		    (headerbuf[0] == '\n')) {
			/* empty line marks end of headers */
			smart_str_0(&tmp_response);
			return tmp_response.s;
		}

		/* add header to collection */
                // Use php_stream_get_s() instead of php_stream_gets()
		n = php_stream_get_s(stream, headerbuf, sizeof(headerbuf) - 1);
		if (n > 0) {
			headerbuf[n] = '\0';
			smart_str_appends(&tmp_response, headerbuf);
		} else {
			smart_str_free(&tmp_response);
			return NULL;
		}
	}

	smart_str_free(&tmp_response);
	return NULL;
}