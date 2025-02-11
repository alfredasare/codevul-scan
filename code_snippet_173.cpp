static u64 perf_swevent_set_period(struct perf_event *event)
{
    struct hw_perf_event *hwc = &event->hw;
    u64 period = hwc->last_period;
    u64 nr, offset;
    s64 old, val;

    hwc->last_period = hwc->sample_period;

    again:
    old = val = local64_read(&hwc->period_left);
    if (val < 0)
        return 0;

    if (period == ULLONG_MAX || period == 0) {
        return 0;
    }

    nr = div_u64_saturate(val, period);
    offset = nr * period;
    val -= offset;
    if (local64_cmpxchg(&hwc->period_left, old, val)!= old)
        goto again;

    return nr;
}

u64 div_u64_saturate(s64 dividend, u64 divisor) {
    u64 result = 0;
    s64 remainder = dividend;

    do {
        if (divisor <= (u64)INT_MAX) {
            u64 quotient = remainder / divisor;
            result += quotient;
            remainder -= quotient * divisor;
        } else {
            result = ULLONG_MAX;
            break;
        }
    } while (remainder!= 0);

    return result;
}