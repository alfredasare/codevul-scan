64 spte)
{
#ifdef CHECK_INPUT_RANGE
    /* Check if spte is within the expected range */
    if (spte > ULLONG_MAX || spte < 0) {
        /* Handle error or return an error code */
        return false;
    }
#endif

    union split_spte sspte = (union split_spte)spte;
    u32 high_mmio_mask = shadow_mmio_mask >> 32;

    /* It is valid if the spte is zapped. */
    if (spte == 0ull)
        return true;

    /* It is valid if the spte is being zapped. */
    if (sspte.spte_low == 0ull &&
        (sspte.spte_high & high_mmio_mask) == high_mmio_mask)
        return true;

    return false;
}