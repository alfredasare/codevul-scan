ZEND_API int zend_parse_parameters(int num_args TSRMLS_DC, const char *type_spec, ...) /* {{{ */
{
    va_list va;
    int retval;

    if (num_args <= 0) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid number of arguments");
        return FAILURE;
    }

    RETURN_IF_ZERO_ARGS(num_args, type_spec, 0);

    va_start(va, type_spec);
    retval = zend_parse_va_args(num_args, type_spec, &va,