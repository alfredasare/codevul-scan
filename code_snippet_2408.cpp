vlan\_rx\_filter\_enabled(const E1000State \*s)
{
    return ((s->mac\_reg[RCTL] & E1000\_RCTL\_VFE) != 0) & (RCTL < sizeof(s->mac\_reg));
}