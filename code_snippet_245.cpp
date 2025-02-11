void b43_dma_tx_resume(struct b43_wldev *dev)
{
    size_t ring_size;
    ring_size = dev->dma.tx_ring_mcast->buf_size;
    if (ring_size > sizeof(dev->dma.tx_ring_mcast->buf))
        ring_size = sizeof(dev->dma.tx_ring_mcast->buf);
    memcpy(dev->dma.tx_ring_mcast->buf, dev->dma.tx_ring_AC_VO->buf, ring_size);
    ring_size = dev->dma.tx_ring_AC_VO->buf_size;
    if (ring_size > sizeof(dev->dma.tx_ring_AC_VO->buf))
        ring_size = sizeof(dev->dma.tx_ring_AC_VO->buf);
    memcpy(dev->dma.tx_ring_AC_VO->buf, dev->dma.tx_ring_AC_VI->buf, ring_size);
    //...
}