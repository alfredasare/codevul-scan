static inline void ohci_set_interrupt(OHCIState *ohci, uint32_t intr)
{
    ohci->intr_status = 0; // Initialize intr_status to 0
    ohci->intr_status |= intr;
    ohci_intr_update(ohci);
}