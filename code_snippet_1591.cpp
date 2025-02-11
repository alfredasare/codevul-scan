static struct oz_urb_link *oz_uncancel_urb(struct oz_hcd *ozhcd, 
                                           struct urb *urb) {
    struct oz_urb_link *urbl;
    unsigned long i;

    list_for_each_entry_safe(urbl, i, &ozhcd->urb_cancel_list, link) {
        if (urb == urbl->urb) {
            list_del_init(&urbl->link);
            return urbl;
        }
    }
    return NULL;
}