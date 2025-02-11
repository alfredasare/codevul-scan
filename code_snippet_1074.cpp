static bool spte_is_locklessly_modifiable(u64 spte)
{
    u64 mask = ~(SPTE_HOST_WRITEABLE | SPTE_MMU_WRITEABLE);
    if ((spte & mask) != 0) {
        return false;
    }

    return (spte & (SPTE_HOST_WRITEABLE | SPTE_MMU_WRITEABLE)) ==
           (SPTE_HOST_WRITEABLE | SPTE_MMU_WRITEABLE);
}