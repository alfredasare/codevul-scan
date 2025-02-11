int br_multicast_set_querier(struct net_bridge *br, unsigned long val)
{
    if (val!= 0 && val!= 1) {
        return -EINVAL;
    }

    bool querier =!!val;

    spin_lock_bh(&br->multicast_lock);
    if (br->multicast_querier == querier)
        goto unlock;

    br->multicast_querier = querier;
    if (querier)
        br_multicast_start_querier(br);

unlock:
    spin_unlock_bh(&br->multicast_lock);

    return 0;
}