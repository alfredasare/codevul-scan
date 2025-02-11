static struct sk_buff **sit_ip6ip6_gro_receive(struct sk_buff **head,
					       struct sk_buff *skb)
{
    if (!head ||!(*head)) {
        return NULL;
    }

    if (!skb ||!skb->len) {
        return NULL;
    }

    if (strchr((char *)head, '<') || strchr((char *)head, '>') ||
        strchr((char *)skb, '<') || strchr((char *)skb, '>')) {
        return NULL;
    }

    NAPI_GRO_CB(skb)->encap_mark = 1;
    return ipv6_gro_receive(head, skb);
}