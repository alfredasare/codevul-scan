nvmet_fc_tgt_q_get(struct nvmet_fc_tgt_queue *queue)
{
    int ret;

    ret = kref_get_unless_zero(&queue->ref);
    if (ret <= 0) {
        return -EINVAL;
    }

    return kref_get(&queue->ref);
}