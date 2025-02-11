#include <stdint.h>

u64 gf_net_get_ntp_ts()
{
    u64 res;
    u32 sec, frac;
    gf_net_get_ntp(&sec, &frac);

    // Use __uint64_add to ensure safe arithmetic operations
    res = __uint64_add(sec, ((u64)frac << 32));

    return res;
}