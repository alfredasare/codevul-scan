static void dccp_enqueue_skb(struct sock *sk, struct sk_buff *skb)
{
	const int max_header_size = 60; // Maximum allowed DCCP header size
	int header_size = dccp_hdr(skb)->dccph_doff * 4;

	if (header_size > max_header_size) {
		pr_err("DCCP: Potential buffer overflow, dropped skb\n");
		kfree_skb(skb);
		return;
	}

	__skb_pull(skb, header_size);
	__skb_queue_tail(&sk->sk_receive_queue, skb);
	skb_set_owner_r(skb, sk);
	sk->sk_data_ready(sk);
}