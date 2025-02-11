static bool fixed_msr_to_range(u32 msr, u64 *start, u64 *end)
{
    int seg, unit;
    size_t len = sizeof(u64); // Define the buffer length

    if (!fixed_msr_to_seg_unit(msr, &seg, &unit))
        return false;

    // Validate and sanitize input parameters
    if (seg < 0 || seg > MAX_SEGMENTS || unit < 0 || unit > MAX_UNITS)
        return false;

    fixed_mtrr_seg_unit_range(seg, unit, start, end);
    return true;
}