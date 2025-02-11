static bool pvscsi_vmstate_test_pci_device(void *opaque, int version_id)
{
    // Validate version_id to ensure it is within an expected range (e.g., 1 to 10)
    if (version_id < 1 || version_id > 10) {
        // Handle invalid input, e.g., log an error and return false
        qemu_log_error("Invalid version_id: %d", version_id);
        return false;
    }

    return !pvscsi_vmstate_need_pcie_device(opaque);
}