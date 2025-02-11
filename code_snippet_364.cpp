void crypto_init_queue(struct crypto_queue *queue, unsigned int max_qlen)
{
	INIT_LIST_HEAD(&queue->list);
	queue->backlog = &queue->list;
	queue->qlen = 0;
	queue->max_qlen = max_qlen;
	crypto_cleanup_queue(queue);
}

void crypto_cleanup_queue(struct crypto_queue *queue)
{
	/* Cleanup and free any resources held by the queue here */
}