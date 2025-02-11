static u32 pegasus_get_msglevel(struct net_device *dev)
{
    pegasus_t *pegasus = netdev_priv(dev);
    size_t size = sizeof(pegasus->msg_enable);

    return *((u32 *)&pegasus->msg_enable);
}