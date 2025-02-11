static inline void vmxnet3_ring_init(Vmxnet3Ring *ring,
                                     hwaddr pa,
                                     size_t size,
                                     size_t cell_size,
                                     bool zero_region)
{
    // Validate input parameters
    if (pa == 0 || size == 0 || cell_size == 0) {
        return;
    }

    // Validate size and cell_size
    if (size > SIZE_MAX || cell_size > SIZE_MAX) {
        return;
    }

    ring->pa = pa;
    ring->size = size;
    ring->cell_size = cell_size;
    ring->gen = VMXNET3_INIT_GEN;
    ring->next = 0;

    if (zero_region) {
        char buffer[size * cell_size];
        memset(buffer, 0, size * cell_size);
        memcpy_s(ring->pa, size * cell_size, buffer, size * cell_size);
    }
}