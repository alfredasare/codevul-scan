static int rtl8150_ioctl(struct net_device *netdev, struct ifreq *rq, int cmd)
{
	rtl8150_t *dev = netdev_priv(netdev);
	u16 *data = (u16 *) & rq->ifr_ifru;
	int res = 0;
	size_t len = sizeof(rq->ifr_ifru)/sizeof(u16);

	switch (cmd) {
	case SIOCDEVPRIVATE:
		if (1 >= len)
			return -EOPNOTSUPP;
		data[0] = dev->phy;
		break;
	case SIOCDEVPRIVATE + 1:
		if (2 >= len)
			return -EOPNOTSUPP;
		read_mii_word(dev, dev->phy, (data[1] & 0x1f), &data[3]);
		break;
	case SIOCDEVPRIVATE + 2:
		if (!capable(CAP_NET_ADMIN))
			return -EPERM;
		if (2 >= len)
			return -EOPNOTSUPP;
		write_mii_word(dev, dev->phy, (data[1] & 0x1f), data[2]);
		break;
	default:
		res = -EOPNOTSUPP;
	}

	return res;
}