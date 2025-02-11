void uwbd_event_queue(struct uwb_event *evt)
{
    struct uwb_rc *rc = evt->rc;
    unsigned long flags;

    if (rc == NULL || evt == NULL) {
        return;
    }

    spin_lock_irqsave(&rc->uwbd.event_list_lock, flags);
    if (rc->uwbd.pid != 0) {
        list_add(&evt->list_node, &rc->uwbd.event_list);
        wake_up_all(&rc->uwbd.wq);
    } else {
        kfree(evt);
    }
    spin_unlock_irqrestore(&rc->uwbd.event_list_lock, flags);
    return;
}