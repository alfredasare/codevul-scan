code:


static inline void pegasus_reset_wol(struct net_device *dev)
{
    struct ethtool_wolinfo wol;
    size_t wol_size = sizeof wol;

    if (wol_size > sizeof wol) {
        pr_err("Error: Insufficient buffer space\n");
        return;
    }

    memset(&wol, 0, wol_size);
    (void) pegasus_set_wol(dev, &wol);
}