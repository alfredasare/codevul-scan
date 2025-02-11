xmlParseURIRaw(const char *str, int raw) {
    xmlURIPtr uri;
    int ret;
    size_t str_len;

    if (str == NULL) {
        return(NULL);
    }

    uri = xmlCreateURI();
    if (uri == NULL) {
        return(NULL);
    }

    str_len = strlen(str);
    if (str_len > XML_MAX_URI_LENGTH) {
        // handle error or truncate the input string
    }

    if (raw) {
        uri->cleanup |= 2;
    }
    ret = xmlParseURIReference(uri, str, str_len);
    if (ret) {
        xmlFreeURI(uri);
        return(NULL);
    }

    return(uri);
}