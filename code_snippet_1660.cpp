static inline void queue_me(struct futex_q *q, struct futex_hash_bucket *hb)
{
    int prio;
    struct plist_node *node;

    spin_lock(&hb->lock);
    prio = min(current->normal_prio, MAX_RT_PRIO);
    node = plist_node_init(&q->list, prio);
    spin_unlock(&hb->lock);

    #ifdef CONFIG_DEBUG_PI_LIST
    q->list.plist.spinlock = &hb->lock;
    #endif
    plist_add(&q->list, &hb->chain);
    q->task = current;
}