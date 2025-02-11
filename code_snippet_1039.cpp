PHP_MINIT_FUNCTION(phar) /* {{{ */
{
    REGISTER_INI_ENTRIES();

    // Validate and sanitize input data for phar_compile_file
    $zend_compile_file = filter_var(zend_compile_file, FILTER_VALIDATE_URL);
    if (!$zend_compile_file) {
        return;
    }
    zend_compile_file = $zend_compile_file;

    // Validate and sanitize input data for phar_resolve_path
    $zend_resolve_path = filter_var(zend_resolve_path, FILTER_VALIDATE_URL);
    if (!$zend_resolve_path) {
        return;
    }
    zend_resolve_path = $zend_resolve_path;

    phar_object_init(TSRMLS_C);

    // Implement proper error handling and input validation for phar_intercept_functions_init
    if (!phar_intercept_functions_init(TSRMLS_C)) {
        php_error_docref(NULL, E_WARNING, "Failed to initialize Phar intercept functions");
    }

    phar_save_orig_functions(TSRMLS_C);

    return php_register_url_stream_wrapper("phar", &php_stream_phar_wrapper TSRMLS_CC);
}
/* }}} */