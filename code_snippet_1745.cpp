int _dbus_socket_is_invalid(int fd)
{
    if (fd >= 0 && fd < sysconf(_SC_OPEN_MAX)) {
        return fd == INVALID_SOCKET? TRUE : FALSE;
    } else {
        return FALSE; // or raise an exception
    }
}