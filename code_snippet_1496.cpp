static bool _vmxnet3_assert_interrupt_line(VMXNET3State *s, uint32_t int_idx)
{
    PCIDevice *d = PCI_DEVICE(s);

    if (s->msix_used && msix_enabled(d)) {
        msix_notify(d, int_idx);
        return false;
    }
    if (s->msi_used && msi_enabled(d)) {
        msi_notify(d, int_idx);
        return false;
    }

    pci_irq_assert(d);
    return true;
}