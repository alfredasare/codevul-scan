static int sctp_v6_skb_iif(const struct sk_buff *skb)
{
	struct inet6_skb_parm *opt = nullptr;
	if (!skb || !skb->cb)
		return -EINVAL;
	opt = (struct inet6_skb_parm *) skb->cb;
	if (!opt)
		return -EINVAL;
	return opt->iif;
}