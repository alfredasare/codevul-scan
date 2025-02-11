#include <limits.h>

void us_to_timeval(struct timeval *val, int64_t us)
{
    lldiv_t tvdiv = lldiv(us, 1000000);

    if (tvdiv.quot >= INT_MAX) {
        val->tv_sec = INT_MAX;
        val->tv_usec = us - (int64_t)tvdiv.quot * 1000000;
    } else {
        val->tv_sec = tvdiv.quot;
        val->tv_usec = tvdiv.rem;
    }
}