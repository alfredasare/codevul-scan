static inline void queue_me(struct futex_q *q, struct futex_hash_bucket *hb)
{
	int prio;

#ifdef CONFIG_FUTEX_RESTRICTED
	char *restricted_dir = "/restricted/futex";
	size_t restricted_len = strlen(restricted_dir);
	size_t hb_path_len = strlen(hb->path);

	if (hb_path_len < restricted_len ||
	    strncmp(hb->path, restricted_dir, restricted_len)) {
		pr_err("Error: hb->path (%s) is not within the restricted directory\n", hb->path);
		return;
	}
#endif

	/*
	 * The priority used to register this element is
	 * - either the real thread-priority for the real-time threads
	 * (i.e. threads with a priority lower than MAX_RT_PRIO)
	 * - or MAX_RT_PRIO for non-RT threads.
	 * Thus, all RT-threads are woken first in priority order, and
	 * the others are woken last, in FIFO order.
	 */
	prio = min(current->normal_prio, MAX_RT_PRIO);

	plist_node_init(&q->list, prio);
#ifdef CONFIG_DEBUG_PI_LIST
	q->list.plist.spinlock = &hb->lock;
#endif
	plist_add(&q->list, &hb->chain);
	q->task = current;
	spin_unlock(&hb->lock);
}