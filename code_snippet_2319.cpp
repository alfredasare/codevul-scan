static int posix_get_monotonic_coarse(clockid_t which_clock, struct timespec64 *tp)
{
#ifdef CLOCK_MONOTONIC_COARSE
    if (which_clock != CLOCK_MONOTONIC_COARSE) {
        return -EINVAL;
    }
#else
    if (which_clock != 0) {
        return -EINVAL;
    }
#endif

    *tp = get_monotonic_coarse64();
    return 0;
}