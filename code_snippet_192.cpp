static int sctp_v6_skb_iif(const struct sk_buff *skb)
{
    if (!skb || skb->cb == NULL)
        return -EINVAL;

    struct inet6_skb_parm *opt = (struct inet6_skb_parm *) skb->cb;
    if (&opt->iif > MAX_IIF_VALUE)
        return -EOVERFLOW;

    return opt->iif;
}