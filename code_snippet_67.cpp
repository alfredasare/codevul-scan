static void do_vapic_enable(void *data)
{
    VAPICROMState *s = data;
    X86CPU *cpu = X86_CPU(first_cpu);

    static const uint8_t enabled = 1;
    cpu_physical_memory_write_masked(s->vapic_paddr + offsetof(VAPICState, enabled),
                                      &enabled, sizeof(enabled));
    apic_enable_vapic(cpu->apic_state, s->vapic_paddr);
    s->state = VAPIC_ACTIVE;
}

void cpu_physical_memory_write_masked(target_phys_addr_t paddr, const void *buf, size_t len) {
    // Implement masking based on your specific requirements
    // For example, you can mask the upper nibble of each byte
    const uint8_t *data = buf;
    for (size_t i = 0; i < len; ++i) {
        data[i] &= 0xF0; // Example mask - replace with appropriate masking technique
    }

    // Continue with the original memory write implementation
    // ...
}