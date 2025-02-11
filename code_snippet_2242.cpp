static inline void ne2000_mem_writeb(NE2000State *s, uint32_t addr, uint32_t val)
{
    if (addr >= NE2000_PMEM_START && addr < NE2000_MEM_SIZE) {
        if (addr < NE2000_MEM_SIZE) {
            s->mem[addr] = val;
        } else {
            // Handle invalid address or out-of-range value
            // e.g., log an error, return an error code, etc.
        }
    } else {
        // Handle invalid address or out-of-range value
        // e.g., log an error, return an error code, etc.
    }
}