static void do_vapic_enable(void *data)
{
    VAPICROMState *s = data;
    X86CPU *cpu = X86_CPU(first_cpu);

    if (!s ||!cpu) {
        return;
    }

    uint8_t enabled = 1;
    memcpy((void *)s->vapic_paddr + offsetof(VAPICState, enabled), &enabled, sizeof(enabled));
    apic_enable_vapic(cpu->apic_state, s->vapic_paddr);
    s->state = VAPIC_ACTIVE;
}