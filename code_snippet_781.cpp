void need_numeric_port_hack(void)
{
    if (!tested_for_getaddrinfo_hacks)
        test_for_getaddrinfo_hacks();

    int port = get_numeric_port(); // Assume this function gets the numeric port value
    if (port < 0 || port > 65535) {
        return;
    }

    char buffer[6]; // Fixed-size buffer for the port number
    sprintf(buffer, "%d", port);
    need_numeric_port_hack_ = buffer;
}