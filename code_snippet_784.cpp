static int php_stream_http_stream_stat(php_stream_wrapper *wrapper, php_stream *stream, php_stream_statbuf *ssb TSRMLS_DC) /* {{{ */
{
	int max_read_attempts = 100; // Limit the number of read attempts
	int bytes_read = 0;
	int ret;

	/* one day, we could fill in the details based on Date: and Content-Length:
	 * headers.  For now, we return with a failure code to prevent the underlying
	 * file's details from being used instead. */

	while (max_read_attempts-- > 0) {
		ret = php_stream_read(stream, ssb->buf + bytes_read, 1 TSRMLS_CC);