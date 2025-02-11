void php_gd_error_method(int type, const char *format, va_list args)
{
	TSRMLS_FETCH();

	int written = php_verror(NULL, "", type, format, args TSRMLS_CC);
	if (written < 0) {
		// Error occurred; handle error and return
		// For example, report the error and terminate the process
		report_error_and_terminate();
		return;
	}
}