static inline void update_t_max_wait(transaction_t *transaction,
				unsigned long ts)
{
#ifdef CONFIG_JBD2_DEBUG
	if (jbd2_journal_enable_debug) {
		unsigned long start = atomic_read(&transaction->t_start);
		if (time_after(start, ts)) {
			ts = jbd2_time_diff(ts, start);
			unsigned long max_wait = atomic_read(&transaction->t_max_wait);
			if (ts > max_wait) {