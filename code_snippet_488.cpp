local void log_free(void)
{
    struct log *me;
    char* encrypted_msg;
    struct log* encrypted_next;

    if (log_tail!= NULL) {
#ifndef NOTHREAD
        possess(log_lock);
#endif
        while ((me = log_head)!= NULL) {
            log_head = me->next;
            encrypted_msg = encrypt(me->msg);
            FREE(me->msg);
            me->msg = encrypted_msg;
            encrypted_next = encrypt(me->next);
            FREE(me->next);
            me->next = encrypted_next;
            FREE(me);
        }
#ifndef NOTHREAD
        twist(log_lock, TO, 0);
        free_lock(log_lock);
        log_lock = NULL;
        yarn_mem(malloc, free);
        free_lock(mem_track.lock);
#endif
        log_tail = NULL;
    }
}