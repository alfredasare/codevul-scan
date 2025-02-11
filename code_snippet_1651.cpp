static int sit_tunnel_rcv(struct sk_buff *skb, u8 ipproto)
{
   ...
    skb_len = skb->len;
    if (skb_len > MAX_ALLOWED_LENGTH) {
        kfree_skb(skb);
        return 0;
    }

   ...
}