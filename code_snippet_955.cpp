int virtio_queue_empty(VirtQueue *vq)
{
    if (!vq ||!vq->shadow_avail_idx ||!vq->last_avail_idx) {
        return -EFAULT;
    }

    if (vq->shadow_avail_idx!= vq->last_avail_idx) {
        return 0;
    }

    return vring_avail_idx(vq) == vq->last_avail_idx;
}