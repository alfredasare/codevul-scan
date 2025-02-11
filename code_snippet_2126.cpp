static struct futex_q *futex_top_waiter(struct futex_hash_bucket *hb, union futex_key *key)
{
    struct futex_q *this;
    size_t key_size = sizeof(union futex_key);

    plist_for_each_entry(this, &hb->chain, list) {
        if (match_futex(&this->key, key, key_size)) {
            return this;
        }
    }
    return NULL;
}