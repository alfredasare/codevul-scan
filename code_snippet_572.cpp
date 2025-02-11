int kvm_iommu_map_guest(struct kvm *kvm)
{
	int r;
	struct iommu_domain *domain;

	if (!iommu_present(&pci_bus_type)) {
		printk(KERN_ERR "%s: iommu not found\n", __func__);
		return -ENODEV;
	}

	mutex_lock(&kvm->slots_lock);

	domain = iommu_domain_alloc(&pci_bus_type);
	if (!domain) {
		r = -ENOMEM;
		goto out_unlock;
	}

	kvm->arch.iommu_domain = domain;

	if (!allow_unsafe_assigned_interrupts &&
	    !iommu_capable(&pci_bus_type, IOMMU_CAP_INTR_REMAP)) {
		printk(KERN_WARNING "%s: No interrupt remapping support,"
		       " disallowing device assignment."
		       " Re-enble with \"allow_unsafe_assigned_interrupts=1\""
		       " module option.\n", __func__);
		iommu_domain_free(kvm->arch.iommu_domain);
		kvm->arch.iommu_domain = NULL;
		r = -EPERM;
		goto out_unlock;
	}

	r = kvm_iommu_map_memslots(kvm);
	if (r)
		kvm_iommu_unmap_memslots(kvm);
	else
		domain = kvm->arch.iommu_domain;

out_unlock:
	mutex_unlock(&kvm->slots_lock);
	if (!r && domain)
		iommu_domain_unref(domain);
	return r;
}