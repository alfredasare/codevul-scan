static netdev\_features\_t dflt\_features\_check(const struct sk\_buff \*skb,
 struct net\_device \*dev,
 netdev\_features\_t features)
{
 if (skb == NULL || dev == NULL) {
 return features;
 }
 return vlan\_features\_check(skb, features);
}