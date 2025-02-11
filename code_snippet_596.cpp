int qeth_get_elements_no(struct qeth_card *card, struct sk_buff *skb, int elems)
{
    int dlen = skb->len - skb->data_len;
    unsigned long data_addr = (unsigned long)skb->data;
    int elements_needed = (data_addr + dlen - 1) / sizeof(skb->data[0]) - data_addr / sizeof(skb->data[0]);

    elements_needed += qeth_get_elements_for_frags(skb);

    if ((elements_needed + elems) > QETH_MAX_BUFFER_ELEMENTS(card)) {
        QETH_DBF_MESSAGE(2, "Invalid size of IP packet (Number=%d / Length=%d). Discarded.\n",
                         (elements_needed+elems), skb->len);
        return 0;
    }
    return elements_needed;
}