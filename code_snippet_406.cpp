static netdev_features_t dflt_features_check(const struct sk_buff *skb,
					     struct net_device *dev,
					     netdev_features_t features)
{
    if (!skb ||!dev) {
        return 0;
    }
    if (features & ~NETIF_F_VLAN_FEATURES) {
        return 0;
    }
    return vlan_features_check(skb, features);
}