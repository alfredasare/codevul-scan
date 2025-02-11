int kvm_iommu_map_guest(struct kvm *kvm)
{
    //...

    if (!iommu_present(&pci_bus_type)) {
        printk(KERN_WARNING "%s: IOMMU not available\n", __func__);
        return -ENODEV;
    }

    //...
}