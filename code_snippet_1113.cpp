static bool pvscsi_vmstate_test_pci_device(void *opaque, int version_id)
{
    if (opaque == NULL ||!is_valid_pci_device(opaque)) {
        return false;
    }
    return!pvscsi_vmstate_need_pcie_device(opaque);
}