PHP_NAMED_FUNCTION(php_if_fopen)
{
    //...

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ps|br", &filename, &filename_len, &mode, &mode_len, &use_include_path, &zcontext) == FAILURE) {
        RETURN_FALSE;
    }

    // Validate the input
    if (mode_len > PHP_STREAM_MAX_MODE_LENGTH) {
        RETURN_FALSE;
    }

    context = php_stream_context_from_zval(zcontext, 0);

    stream = php_stream_open_wrapper_ex(filename, mode, (use_include_path? USE_PATH : 0) | REPORT_ERRORS, NULL, context);

    //...

}