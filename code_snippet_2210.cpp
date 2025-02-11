static int get_freq(RangeCoder *rc, unsigned total_freq, unsigned *freq)
{
    if (total_freq <= 0)
        return AVERROR_INVALIDDATA;

    total_freq = atoi(sanitized_str(total_freq));

    if (total_freq == 0)
        return AVERROR_INVALIDDATA;

    rc->range = rc->range / total_freq;

    if (rc->range == 0)
        return AVERROR_INVALIDDATA;

    *freq = rc->code / rc->range;

    return 0;
}

static char *sanitized_str(unsigned val) {
    char *str = malloc(32);
    sprintf(str, "%u", val);
    return str;
}