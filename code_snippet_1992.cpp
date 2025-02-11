SAPI_API int sapi_register_treat_data(void (*treat_data)(int arg, char *str, zval *destArray TSRMLS_DC) TSRMLS_DC)
{
    if (!treat_data || !str || !destArray) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid or null pointer provided in parameters");
        return FAILURE;
    }

    if (SG(sapi_started) && EG(in_execution)) {
        return FAILURE;
    }

    sapi_module.treat_data = treat_data;
    return SUCCESS;
}