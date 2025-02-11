static inline void update_t_max_wait(transaction_t *transaction, unsigned long ts)
{
#ifdef CONFIG_JBD2_DEBUG
    if (jbd2_journal_enable_debug && time_after(transaction->t_start, ts)) {
        // Whitelist validation
        const unsigned long whitelist[] = {0, 100, 200, 300}; // Example whitelist
        if (!is_in_range(ts, whitelist, sizeof(whitelist) / sizeof(whitelist[0]))) {
            return; // Invalid 'ts' value, return error
        }

        ts = jbd2_time_diff(ts, transaction->t_start);
        spin_lock(&transaction->t_handle_lock);
        if (ts > transaction->t_max_wait)
            transaction->t_max_wait = ts;
        spin_unlock(&transaction->t_handle_lock);
    }
#endif
}

bool is_in_range(unsigned long ts, const unsigned long *whitelist, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (ts >= whitelist[i] && ts <= whitelist[i + 1]) {
            return true;
        }
    }
    return false;
}