static void native_flush_tlb_one_user(unsigned long addr)
{
#ifdef CONFIG_ARM64
    if (addr >= TRAMPOLINE_BASE && addr < TRAMPOLINE_BASE + TRAMPOLINE_SIZE) {
        __native_flush_tlb_one_user(addr);
    } else {
        pr_err("Attempt to access out-of-bounds address: 0x%lx\n", addr);
    }
#else
    // Add input validation for other platforms
    if (isValidAddress(addr)) {
        __native_flush_tlb_one_user(addr);
    } else {
        pr_err("Attempt to access out-of-bounds address: 0x%lx\n", addr);
    }
#endif
}