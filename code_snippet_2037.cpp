ZEND_API int zend_eval_string_ex(char *str, zval *retval_ptr, char *string_name, int handle_exceptions) /* {{{ */
{
    char *sanitized_str = validate_string(str);
    if (sanitized_str == NULL) {
        return ZEND_ERROR;
    }
    return zend_eval_stringl_ex(sanitized_str, strlen(sanitized_str), retval_ptr, string_name, handle_exceptions);
}

char *validate_string(char *str) {
    if (str == NULL) return str;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '%' || str[i] =='s') {
            return NULL; // Input string is invalid
        }
    }
    return str;
}