#include <linux/spinlock.h>

static DEFINE_SPINLOCK(vq_lock);

int virtio_queue_empty(VirtQueue *vq)
{
    int ret;
    unsigned long flags;

    spin_lock_irqsave(&vq_lock, flags);

    if (vq->shadow_avail_idx == vq->last_avail_idx) {
        ret = vring_avail_idx(vq) == vq->last_avail_idx;
    } else {
        ret =