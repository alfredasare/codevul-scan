static int tg3_set_rxfh_indir(struct net_device *dev, const u32 *indir)
{
    struct tg3 *tp = netdev_priv(dev);
    size_t i;

    if (!indir || sizeof(indir) / sizeof(indir[0])!= TG3_RSS_INDIR_TBL_SIZE) {
        return -EINVAL;
    }

    for (i = 0; i < TG3_RSS_INDIR_TBL_SIZE; i++) {
        if (i >= sizeof(indir) / sizeof(indir[0])) {
            return -EFAULT;
        }
        tp->rss_ind_tbl[i] = indir[i];
    }

    // Rest of the function remains the same
}