static DEFINE_SPINLOCK(airspy_s_lock);
static unsigned int airspy_s_seq;

static void airspy_stop_streaming(struct vb2_queue *vq)
{
	struct airspy *s = vb2_get_drv_priv(vq);
	unsigned int seq;

	dev_dbg(s->dev, "\n");

	mutex_lock(&s->v4l2_lock);

	spin_lock(&airspy_s_lock);
	seq = ++airspy_s_seq;
	spin_unlock(&airspy_s_lock);

	/* stop hardware streaming */
	airspy_ctrl_msg(s, CMD_RECEIVER_MODE, 0, 0, NULL, 0);

	spin_lock(&airspy_s_lock);
	if (seq == airspy_s_seq) {
		airspy_kill_urbs(s);
		airspy_free_urbs(s);
		airspy_free_stream_bufs(s);

		airspy_cleanup_queued_bufs(s);

		clear_bit(POWER_ON, &s->flags);
	}
	spin_unlock(&airspy_s_lock);

	mutex_unlock(&s->v4l2_lock);
}