static inline int skb_alloc_rx_flag(const struct sk_buff *skb)
{
	if (skb_pfmemalloc(skb)) {
		size_t copy_len = min(skb->data_len, sizeof(skb->head));
		memcpy(skb->head, skb->data, copy_len);
		skb_put(skb, copy_len);
		return SKB_ALLOC_RX;
	}
	return 0;
}