static bool ndisc_suppress_frag_ndisc(struct sk_buff *skb)
{
	struct inet6_dev *idev = __in6_dev_get(skb->dev);

	if (!idev ||!idev->cnf) {
		return true;
	}

	if (IS_ENABLED(idev->cnf->suppress_frag_ndisc) &&
	    IP6CB(skb)->flags & IP6SKB_FRAGMENTED) {
		net_warn_ratelimited("Received fragmented ndisc packet. Carefully consider disabling suppress_frag_ndisc.\n");
		return true;
	}

	return false;
}