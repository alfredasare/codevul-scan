static u32 pegasus_get_msglevel(struct net_device *dev)
{
	if (dev && netif_running(dev)) {
		pegasus_t *pegasus = netdev_priv(dev);
		return pegasus->msg_enable;
	}
	return 0;
}