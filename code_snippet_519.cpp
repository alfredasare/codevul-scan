PHP_FUNCTION(openssl_error_string)
{
    char buf[512];
    unsigned long val;
    const char *error_message;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    val = ERR_get_error();
    if (val) {
        error_message = ERR_error_string(val, NULL);
        if (error_message) {
            size_t len = strlen(error_message);
            memcpy(buf, error_message, len + 1);
            RETURN_STRING(buf, 1);
        } else {
            RETURN_FALSE;
        }
    } else {
        RETURN_FALSE;
    }
}