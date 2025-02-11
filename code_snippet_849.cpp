static bool signed_sub_overflows(s64 a, s64 b)
{
    /* Cast signed integers to unsigned integers before subtraction */
    s64 res = (s64)((uint64_t)a - (uint64_t)b);

    if (b < 0)
        return res < a;
    return res > a;
}