static zend_string *get_http_headers(php_stream *stream)
{
    smart_str tmp_response = {0};
    char headerbuf[32768]; // Increased buffer size to 32768

    while (php_stream_gets(stream, headerbuf, sizeof(headerbuf))) {
        if ((headerbuf[0] == '\r' && headerbuf[1] == '\n') ||
            (headerbuf[0] == '\n')) {
            /* empty line marks end of headers */
            smart_str_0(&tmp_response);
            return tmp_response.s;
        }

        /* add header to collection */
        smart_str_append(&tmp_response, headerbuf, strlen(headerbuf));
    }

    smart_str_free(&tmp_response);
    return NULL;
}