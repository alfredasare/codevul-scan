void rose_frames_acked(struct sock *sk, unsigned short nr)
{
    struct sk_buff *skb;
    struct rose_sock *rose = rose_sk(sk);
    int i, queue_size;

    /* Remove all the ack-ed frames from the ack queue. */
    if (rose->va!= nr) {
        queue_size = skb_queue_len(&rose->ack_queue);
        for (i = 0; i < queue_size; i++) {
            skb = skb_dequeue(&rose->ack_queue);
            kfree_skb(skb);
        }
        rose->va = (rose->va + 1) % ROSE_MODULUS;
    }
}