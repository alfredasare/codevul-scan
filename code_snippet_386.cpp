static uint32_t process_cpu_nsleep(const clockid_t which_clock, uint32_t flags,
			      const struct timespec64 *rqtp)
{
    if (flags > 1) {
        return -EINVAL;
    }
    return posix_cpu_nsleep(PROCESS_CLOCK, flags, rqtp);
}