void crypto_init_queue(struct crypto_queue *queue, unsigned int max_qlen)
{
    if (queue) {
        INIT_LIST_HEAD(&queue->list);
        queue->backlog = &queue->list;
        queue->qlen = 0;
        queue->max_qlen = max_qlen;
    } else {
        printk(KERN_ERR "Error: queue is NULL\n");
        return;
    }
}