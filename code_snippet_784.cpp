php
PHP_MINFO_FUNCTION(basic) /* {{{ */
{
    php_info_print_table_start();
    try {
        PHP_MINFO(dl)(ZEND_MODULE_INFO_FUNC_ARGS_PASSTHRU);
        PHP_MINFO(mail)(ZEND_MODULE_INFO_FUNC_ARGS_PASSTHRU);
        PHP_MINFO(assert)(ZEND_MODULE_INFO_FUNC_ARGS_PASSTHRU);
    } catch (Exception $e) {
        // Handle the exception and release resources as necessary
    } finally {
        php_info_print_table_end();
    }
}
/* }}} */