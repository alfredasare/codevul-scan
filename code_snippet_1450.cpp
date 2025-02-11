int xmlrpc_getlast_error(void)
{
    char *error_message = xmlrpc_error_message(xmlrpc_error_code);
    if (strchr(error_message, '/')!= NULL) {
        return -1; // or some other error code
    }
    return xmlrpc_error_code;
}