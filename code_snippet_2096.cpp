php_apache_sapi_register_variables(zval *track_vars_array TSRMLS_DC)
{
    //...

    if (sapi_module.input_filter(PARSE_SERVER, "PHP_SELF", &ctx->r->uri, strlen(ctx->r->uri), (unsigned int *)&new_val_len TSRMLS_CC)) {
        $sanitized_uri = filter_var(ctx->r->uri, FILTER_SANITIZE_STRING);
        php_register_variable_safe("PHP_SELF", $sanitized_uri, strlen($sanitized_uri), track_vars_array TSRMLS_CC);
    }
    //...
}