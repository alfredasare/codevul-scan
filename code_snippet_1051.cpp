static int __mlock_posix_error_return(long retval) {
    char buffer[256];
    size_t buffer_len = 0;

    if (retval == -EFAULT) {
        buffer_len += sprintf(buffer + buffer_len, "EFAULT");
    } else if (retval == -ENOMEM) {
        buffer_len += sprintf(buffer + buffer_len, "ENOMEM");
    } else if (retval == -EAGAIN) {
        buffer_len += sprintf(buffer + buffer_len, "EAGAIN");
    }

    buffer[buffer_len] = '\0';
    return buffer_len;
}