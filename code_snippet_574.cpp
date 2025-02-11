local void log_free(void)
    {
        struct log *me, *next;

        if (log_tail != NULL) {
#ifndef NOTHREAD
            possess(log_lock);
#endif
            me = log_head;
            while (me != NULL) {
                next = me->next;
                if (me->msg != NULL) {
                    FREE(me->msg);
                }
                FREE(me);
                me = next;
            }

#ifndef NOTHREAD
            twist(log_lock, TO, 0);
            free_lock(mem_track.lock);
#endif
            log_lock = NULL;
            yarn_mem(malloc, free);
            free_lock(mem_track.lock);
        }
        log_tail = NULL;
    }