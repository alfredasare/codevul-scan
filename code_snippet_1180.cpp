#define MAX_IP6_PAYLOAD_LEN (65535 - sizeof(struct ip6_hdr))

static int ip6_finish_output(struct sk_buff *skb)
{
	if ((skb->len > ip6_skb_dst_mtu(skb) && !skb_is_gso(skb)) ||
	    dst_allfrag(skb_dst(skb)) ||
	    (skb->len > MAX_IP6_PAYLOAD_LEN && skb->data + skb->len <= skb->head + skb->tail))
		return ip6_fragment(skb, ip6_finish_output2);
	else
		return ip6_finish_output2(skb);
}