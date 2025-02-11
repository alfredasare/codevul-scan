void blkcg_drain_queue(struct request_queue *q)
{
	lockdep_assert_held(q->queue_lock);

	/* Save the root_blkg before checking it, to avoid TOCTOU vulnerability */
	struct blkg\_group *root\_blkg = q->root\_blkg;

	if (!root\_blkg)
		return;

	blk\_throtl\_drain(q);
}