static void __bnep_unlink_session(struct bnep_session *s)
{
    spin_lock_irq(&bnep_session_list_lock);
    if (!list_empty(&s->list)) {
        list_del(&s->list);
    }
    spin_unlock_irq(&bnep_session_list_lock);
}