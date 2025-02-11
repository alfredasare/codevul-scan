Introduce a maximum size check for the `sk_buff` structure to prevent buffer overflow:

    Code:
    #define MAX_SKB_DATA_SIZE 65535

    int raw_local_deliver(struct sk_buff *skb, int protocol)
    {
        int hash;
        struct sock *raw_sk;

        hash = protocol & (RAW_HTABLE_SIZE - 1);
        raw_sk = sk_head(&raw_v4_hashinfo.ht[hash]);

        /* If there maybe a raw socket we must check - if not we
        * don't care less */
        if (skb && skb->len <= MAX_SKB_DATA_SIZE && raw_sk && !raw_v4_input(skb, ip_hdr(skb), hash))
            raw_sk = NULL;

        return raw_sk != NULL;

    }