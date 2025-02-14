atusb_set_txpower(struct ieee802154_hw *hw, s32 mbm)
{
    struct atusb *atusb = hw->priv;
    u32 i;

    if (mbm < 0 || mbm >= hw->phy->supported.tx_powers_size ||
        hw->phy->supported.tx_powers[mbm] != mbm) {
        return -EINVAL;
    }

    for (i = 0; i < hw->phy->supported.tx_powers_size; i++) {
        if (hw->phy->supported.tx_powers[i] == mbm)
            return atusb_write_subreg(atusb, SR_TX_PWR_23X, i);
    }

    return -EINVAL;
}