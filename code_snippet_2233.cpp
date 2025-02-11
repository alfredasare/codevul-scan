struct futex_hash_bucket {
	spinlock_t lock;
	unsigned int n_chains;
	struct hlist_head chain[0];
};

static struct futex_q *futex_top_waiter(struct futex_hash_bucket *hb,
				union futex_key *key)
{
	struct futex_q *this;
	spin_lock(&hb->lock);
	plist_for_each_entry(this, &hb->chain, list) {
		if (match_futex(&this->key, key)) {
			spin_unlock(&hb->lock);
			return this;
		}
	}
	spin_unlock(&hb->lock);
	return NULL;
}