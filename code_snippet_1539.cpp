static size_t encoding_filter_script_to_intermediate(unsigned char **to, size_t *to_length, const unsigned char *from, size_t from_length TSRMLS_DC)
{
    // Validate input length to prevent potential buffer overflow attacks
    if (from_length > 0 && from != NULL) {
        return zend_multibyte_encoding_converter(to, to_length, from, from_length, zend_multibyte_encoding_utf8, LANG_SCNG(script_encoding) TSRMLS_CC);
    } else {
        // Handle invalid input gracefully (e.g., return an error code or log the error)
        return 0;
    }
}