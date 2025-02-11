static const SSL_METHOD *ssl3_get_server_method(int ver)
{
    SSL_METHOD *method = NULL;
    if (ver == SSL3_VERSION) {
        method = SSLv3_server_method();
        if (method == NULL) {
            // Handle error case
            //...
        }
    }
    return method;
}