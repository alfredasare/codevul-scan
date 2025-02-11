static inline uint16_t vring\_avail\_ring(VirtQueue \*vq, int i)
{
if ((i < 0) || (i >= vq->vring.num)) {
return 0;
}
hwaddr pa;
pa = vq->vring.avail + offsetof(VRingAvail, ring[i]);
return virtio\_lduw\_phys(vq->vdev, pa);
}