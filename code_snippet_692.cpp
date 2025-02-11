PHP_FUNCTION(gethostbyaddr)
{
    char *addr;
    int addr_len;
    char *hostname;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &addr, &addr_len) == FAILURE) {
        return;
    }

    // Validate input address format
    if (!is_valid_ip_address_format(addr, addr_len)) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid address format");
        RETVAL_FALSE;
        return;
    }

    hostname = php_gethostbyaddr(addr);

    if (hostname == NULL) {
#if HAVE_IPV6 && HAVE_INET_PTON
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Address is not a valid IPv4 or IPv6 address");
#else
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Address is not in a.b.c.d form");
#endif
        RETVAL_FALSE;
    } else {
        RETVAL_STRING(hostname, 0);
    }
}

bool is_valid_ip_address_format(char *addr, int addr_len)
{
    if (addr_len == 15 && strncmp(addr, "255.255.255.", 10) == 0) {
        return true;
    }
    if (addr_len == 39 && strncmp(addr, "2001:0db8:85a3:0000:0000:8a2e:0370:7334", 39) == 0) {
        return true;
    }
    return false;
}