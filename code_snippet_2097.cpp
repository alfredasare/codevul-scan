static void dccp_enqueue_skb(struct sock *sk, struct sk_buff *skb)
{
    int doff = dccp_hdr(skb)->dccph_doff;
    if (doff < DCCP_MIN_DOFF || doff > DCCP_MAX_DOFF) {
        return;
    }

    __skb_pull(skb, doff * 4);
    __skb_queue_tail(&sk->sk_receive_queue, skb);
    skb_set_owner_r(skb, sk);
    sk->sk_data_ready(sk);
}