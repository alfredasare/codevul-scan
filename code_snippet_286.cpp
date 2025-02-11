int compat_get_timespec64(struct timespec64 *ts, const void __user *uts)
{
    char buffer[32]; // assume a maximum size for the buffer
    if (COMPAT_USE_64BIT_TIME) {
        if (copy_from_user(buffer, uts, sizeof(struct timespec64)))
            return -EFAULT;
        ts->tv_sec = kstrtoul(buffer, 0, &ts->tv_sec);
        ts->tv_nsec = kstrtoul(buffer + 16, 0, &ts->tv_nsec);
    } else {
        return __compat_get_timespec64(ts, uts);
    }
    return 0;
}