static int dcbnl_getcap(struct net_device *netdev, struct nlmsghdr *nlh,
                         u32 seq, struct nlattr **tb, struct sk_buff *skb)
{
   ...
    nest = nla_nest_start(skb, DCB_ATTR_CAP);
    if (!nest) {
        ret = -EMSGSIZE;
        goto err_nest;
    }
   ...
    nla_nest_end(skb, nest);
    err_nest:
    return ret;
}