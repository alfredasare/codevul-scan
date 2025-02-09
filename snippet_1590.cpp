PHP_MINIT_FUNCTION(phar) /* {{{ */
{
	REGISTER_INI_ENTRIES();

	phar_orig_compile_file = zend_compile_file;
	zend_compile_file = phar_compile_file;

	phar_save_resolve_path = zend_resolve_path;
	zend_resolve_path = phar_resolve_path;

	phar_object_init(TSRMLS_C);

	phar_intercept_functions_init(TSRMLS_C);
	phar_save_orig_functions(TSRMLS_C);

	return php_register_url_stream_wrapper("phar", &php_stream_phar_wrapper TSRMLS_CC);
}
/* }}} */
