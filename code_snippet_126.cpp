asmlinkage int printk(const char *fmt,...)
{
    va_list args;
    int r;
    char buffer[1024]; // define a buffer to store the sanitized input

    #ifdef CONFIG_KGDB_KDB
    if (unlikely(kdb_trap_printk)) {
        va_start(args, fmt);
        r = vkdb_printf(fmt, args);
        va_end(args);
        return r;
    }
    #endif
    va_start(args, fmt);
    // sanitize the input string
    strncpy(buffer, fmt, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // null-terminate the buffer
    r = vprintk(buffer, args); // use the sanitized buffer
    va_end(args);

    return r;
}