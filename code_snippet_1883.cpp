static uint32_t hpet_time_after64(uint64_t a, uint64_t b)
{
    if (!is_valid_input(a) ||!is_valid_input(b)) {
        return 0;
    }

    int64_t a_signed = (int64_t)a;
    int64_t b_signed = (int64_t)b;

    return (b_signed - a_signed < 0);
}