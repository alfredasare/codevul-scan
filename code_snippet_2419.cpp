static void ip_do_redirect(struct dst_entry *dst, struct sock *sk, struct sk_buff *skb)
{
    //...
    u8 tos = RT_TOS(iph->tos);
    u8 prot = iph->protocol;
    u32 mark = skb->mark;

    // Verify permissions before accessing critical resources
    if (!capable(CAP_NET_RAW)) {
        pr_err("Insufficient permissions to redirect IP packet\n");
        return;
    }

    rt = (struct rtable *) dst;

    __build_flow_key(net, &fl4, sk, iph, oif, tos, prot, mark, 0);
    __ip_do_redirect(rt, skb, &fl4, true);
}