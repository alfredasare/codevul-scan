static inline uint16_t vring_avail_ring(VirtQueue *vq, int i)
{
    if (i < 0 || i >= vq->vring.avail->ring_size) {
        return 0;
    }

    hwaddr pa;
    pa = vq->vring.avail + offsetof(VRingAvail, ring[i]);
    return virtio_lduw_phys(vq->vdev, pa);
}