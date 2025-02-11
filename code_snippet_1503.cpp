nvmet_fc_tgt_q_get(struct nvmet_fc_tgt_queue *queue)
{
	if (kref_get_unless_zero(&queue->ref))
		return queue;
	return NULL;
}