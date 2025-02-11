static inline void safe_add32(uint32_t *a, uint32_t b) {
    uint64_t sum = (uint64_t)(*a) + b;
    if ((sum - b) != *a) {
        *a = (uint32_t)sum;
    }
}

void gcm_bytecounter_add(uint32_t ctr[2], size_t add) {
    if (sizeof(add) > sizeof(u32)) {
        uint32_t high_add = (((uint64_t)add >> 31) >> 1) & 0xffffffff;
        safe_add32(&ctr[1], high_add);
    }

    safe_add32(&ctr[0], add);

    if (ctr[0] < add) {
        safe_add32(&ctr[1], 1);
    }
}