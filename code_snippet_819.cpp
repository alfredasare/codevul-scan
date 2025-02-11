static inline void pegasus\_reset\_wol(struct net\_device \*dev)
{
 struct ethtool\_wolinfo wol = {0};

 if (dev != NULL) {
 pegasus\_set\_wol(dev, &wol);
 }
}