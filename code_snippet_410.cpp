static int process_cpu_nsleep(const clockid_t which_clock, int flags,
                               const struct timespec64 *rqtp)
{
    /* Validate the clock ID just before usage */
    if (which_clock != PROCESS_CLOCK) {
        return -EINVAL;
    }

    return posix_cpu_nsleep(which_clock, flags, rqtp);
}