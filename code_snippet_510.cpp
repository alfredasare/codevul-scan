void us_to_timeval(struct timeval *val, int64_t us)
{
    if (us < 0 || us > INT64_MAX) {
        return;
    }

    struct timeval tv;
    tv.tv_sec = us / 1000000;
    tv.tv_usec = us % 1000000;
    *val = tv;
}