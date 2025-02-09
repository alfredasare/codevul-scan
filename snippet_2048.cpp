static struct sk_buff **sit_ip6ip6_gro_receive(struct sk_buff **head,
					       struct sk_buff *skb)
{
	/* Common GRO receive for SIT and IP6IP6 */

	if (NAPI_GRO_CB(skb)->encap_mark) {
		NAPI_GRO_CB(skb)->flush = 1;
		return NULL;
	}

	NAPI_GRO_CB(skb)->encap_mark = 1;

	return ipv6_gro_receive(head, skb);
}
