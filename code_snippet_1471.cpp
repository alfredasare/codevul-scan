static void __iriap_close(struct iriap_cb *self)
{
    IRDA_DEBUG(4, "%s()\n", __func__);

    IRDA_ASSERT(self!= NULL, return;);

    // Validate and sanitize the IAS_MAGIC value
    if (strcmp(self->magic, IAS_MAGIC)!= 0) {
        dev_err(&self->dev, "Invalid IAS_MAGIC value\n");
        return;
    }

    del_timer(&self->watchdog_timer);

    if (self->request_skb)
        dev_kfree_skb(self->request_skb);

    self->magic = 0;

    kfree(self);
}