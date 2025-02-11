int qeth_get_elements_no(struct qeth_card *card, struct sk_buff *skb, int elems)
{
	if (skb->len < skb->data_len || skb->len > MAX_SKB_LEN) {
		QETH_DBF_MESSAGE(2, "Invalid SKB properties. Discarded.\n");
		return 0;
	}

	int dlen = skb_put(skb, 0) - skb->data;
	if (!dlen) {
		QETH_DBF_MESSAGE(2, "skb_put() failed. Discarded.\n");
		return 0;
	}

	int max_dlen = INT_MAX - (sizeof(skb->data) - 1);
	if (dlen > max_dlen) {
		QETH_DBF_MESSAGE(2, "Integer overflow detected. Discarded.\n");
		return 0;
	}

	int elements_needed = PFN_UP((unsigned long)skb->data + dlen - 1) -
		PFN_DOWN((unsigned long)skb->data);

	elements_needed += qeth_get_elements_for_frags(skb);

	if ((elements_needed + elems) > QETH_MAX_BUFFER_ELEMENTS(card)) {
		QETH_DBF_MESSAGE(2, "Invalid size of IP packet "
			"(Number=%d / Length=%d). Discarded.\n",
			(elements_needed+elems), skb->len);
		return 0;
	}
	return elements_needed;
}