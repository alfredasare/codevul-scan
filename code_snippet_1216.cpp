void jbd2_journal_unlock_updates (journal_t *journal)
{
        if (!journal || !journal->j_barrier_count) {
                /* Handle error or return early */
                return;
        }

        J_ASSERT(journal->j_barrier_count != 0);

        write_lock(&journal->j_state_lock);
        if (journal->j_barrier_count <= 0) {
                /* Handle error or return early */
                write_unlock(&journal->j_state_lock);
                return;
        }
        mutex_unlock(&journal->j_barrier);
        --journal->j_barrier_count;
        write_unlock(&journal->j_state_lock);
        wake_up(&journal->j_wait_transaction_locked);
}