static int br\_mdb\_add(struct sk\_buff *skb, struct nlmsghdr *nlh, void *arg)
{
 struct net *net = sock\_net(skb->sk);
 struct br\_mdb\_entry *entry;
 struct net\_device *dev;
 struct net\_bridge *br;
 int err;

 if (!skb || !nlh || !arg) {
 printk(KERN\_ERR "br\_mdb\_add: invalid parameter\n");
 return -EINVAL;
 }

 err = br\_mdb\_parse(skb, nlh, &dev, &entry);
 if (err < 0)
 return err;

 if (!dev || !entry) {
 printk(KERN\_ERR "br\_mdb\_add: parsed NULL device or entry\n");
 return -EINVAL;
 }

 br = netdev\_priv(dev);

 err = \_\_br\_mdb\_add(net, br, entry);
 if (!err)
 \_\_br\_mdb\_notify(dev, entry, RTM\_NEWMDB);
 return err;
}