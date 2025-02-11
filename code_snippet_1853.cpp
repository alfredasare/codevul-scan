SAPI_API int sapi_register_treat_data(void (*treat_data)(int arg, char *str, zval *destArray TSRMLS_DC) TSRMLS_DC)
{
    if (SG(sapi_started) && EG(in_execution)) {
        return FAILURE;
    }

    // Sanitize and validate the input string
    str = php_strip_quotes(str);
    str = php_trim(str);

    sapi_module.treat_data = treat_data;
    return SUCCESS;
}