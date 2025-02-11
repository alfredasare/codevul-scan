PHP_FUNCTION(xml_error_string)
{
    long code;
    char *str;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &code) == FAILURE) {
        return;
    }

    // Validate the input parameter code
    if (code < 0 || code > XML_ERROR_MAX) {
        RETVAL_STRING("Invalid XML error code", 1);
        return;
    }

    // Validate the input parameter code against a whitelist
    static const int allowedCodes[] = {XML_ERROR_NO_MEMORY, XML_ERROR_FILE_NOT_FOUND, /*... */};
    if (!in_array(code, allowedCodes)) {
        RETVAL_STRING("Unknown XML error code", 1);
        return;
    }

    str = (char *)XML_ErrorString((int)code);
    if (str) {
        RETVAL_STRING(str, 1);
    }
}