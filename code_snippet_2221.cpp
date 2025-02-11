static inline void eth_pulse_irq(struct xlx_ethlite *s)
{
    if (s && s->regs) {
        if (R_TX_GIE0 < ARRAY_SIZE(s->regs) &&
            s->regs[R_TX_GIE0] & GIE_GIE) {
            qemu_irq_pulse(s->irq);
        }
    }
}