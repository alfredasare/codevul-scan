int sk_filter(struct sock *sk, struct sk_buff *skb)
{
    //... (rest of the function remains the same)

    rcu_read_lock();
    filter = rcu_dereference(sk->sk_filter);
    if (filter) {
        unsigned int pkt_len = SK_RUN_FILTER(filter, skb);

        if (pkt_len > skb->len) {
            err = -EPERM; // or handle the error as needed
        } else {
            err = pkt_len ? pskb_trim(skb, pkt_len) : -EPERM;
        }
    }
    rcu_read_unlock();

    return err;
}