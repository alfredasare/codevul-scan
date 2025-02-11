static const SSL_METHOD *ssl3_get_server_method(int ver)
{
    const SSL_METHOD *method = NULL;

    if (ver == SSL3_VERSION) {
        method = SSLv23_server_method();

        /* Check if the method is available and suitable */
        if (method != NULL && SSL_version_supported(method, ver)) {
            return method;
        }
    }

    /* If no suitable method is found, return NULL */
    return (NULL);
}