static inline void eth_pulse_irq(struct xlx_ethlite *s)
{
volatile uint32_t gie0\_value;

gie0\_value = s->regs[R\_TX\_GIE0];

/* Only the first gie reg is active. */
if (gie0\_value & GIE\_GIE) {
qemu\_irq\_pulse(s->irq);
}

s->regs[R\_TX\_GIE0] = gie0\_value;
}