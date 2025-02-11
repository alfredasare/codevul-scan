vlan_rx_filter_enabled(E1000State *s)
{
    uint16_t rctl = s->mac_reg[RCTL];
    uint16_t max_vfe = E1000_RCTL_VFE_MAX; 

    if (rctl >= max_vfe) {
        return FALSE;
    }

    return (rctl & ((1 << E1000_RCTL_VFE_SHIFT) - 1)) == (1 << E1000_RCTL_VFE_SHIFT - 1);
}