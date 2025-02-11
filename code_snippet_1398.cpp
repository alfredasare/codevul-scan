static size_t encoding_filter_script_to_intermediate(unsigned char **to, size_t *to_length, const unsigned char *from, size_t from_length TSRMLS_DC)
{
    // Validate input data length
    if (from_length > *to_length) {
        return 0; // or handle error accordingly
    }

    // Use safer conversion library
    int conv_len = iconv((iconv_t)0, "", "", to, from_length);
    if (conv_len == (size_t)-1) {
        return 0; // or handle error accordingly
    }

    // Update to_length and return
    *to_length = conv_len;
    return conv_len;
}