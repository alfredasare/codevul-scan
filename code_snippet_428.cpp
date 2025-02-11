php
PHP_FUNCTION(set_magic_quotes_runtime)
{
    zend_bool new_setting;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &new_setting) == FAILURE) {
        return;
    }

    if (new_setting) {
        php_error_docref(NULL TSRMLS_CC, E_DEPRECATED, "set_magic_quotes_runtime is no longer supported");
    }
    return;
}