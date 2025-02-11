static void __iriap_close(struct iriap_cb *self)
{
	IRDA_DEBUG(4, "%s()\n", __func__);

	if (self == NULL) {
		IRDA_ERR("Null self pointer\n");
		return;
	}

	IRDA_ASSERT(self->magic == IAS_MAGIC, return;);

	del_timer(&self->watchdog_timer);

	if (self->request_skb != NULL)
		dev_kfree_skb(self->request_skb);

	self->magic = 0;

	kfree(self);
}