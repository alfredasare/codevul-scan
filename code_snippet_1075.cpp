static int do\_set\_master(struct net\_device \*dev, int ifindex)
{
 const struct net\_device\_ops \*ops;
 int err = 0;

 if (ifindex) {
 struct net\_device \*upper\_dev = __dev\_get\_by\_index(dev\_net(dev), ifindex);

 if (!upper\_dev || !upper\_dev->netdev\_ops || !upper\_dev->netdev\_ops->ndo\_add\_slave)
 return -EINVAL;

 ops = upper\_dev->netdev\_ops;
 err = ops->ndo\_add\_slave(upper\_dev, dev);
 }

 return err;
}