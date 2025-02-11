void blk_post_runtime_suspend(struct request_queue *q, int err)
{
	struct device *dev = q->dev;

	if (!dev)
		return;

	spin_lock_irq(q->queue_lock);
	if (!err) {
		q->rpm_status = RPM_SUSPENDED;
	} else {
		q->rpm_status = RPM_ACTIVE;
		get_device(dev);
		pm_runtime_mark_last_busy(dev);
		put_device(dev);
	}
	spin_unlock_irq(q->queue_lock);
}