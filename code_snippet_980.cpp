static inline int sock_sendto(php_netstream_data_t *sock, const char *buf, size_t buflen, int flags, struct sockaddr *addr, socklen_t addrlen)
{
    int ret;
    if (addr) {
        ret = sendto(sock->socket, buf, (buflen <= INT_MAX)? buflen : INT_MAX, flags, addr, addrlen);
        return (ret == SOCK_CONN_ERR)? -1 : ret;
    }
#ifdef PHP_WIN32
    ret = send(sock->socket, buf, (buflen <= INT_MAX)? buflen : INT_MAX, flags);
#else
    ret = send(sock->socket, buf, buflen, flags);
#endif
    return ((ret == SOCK_CONN_ERR)? -1 : ret);
}