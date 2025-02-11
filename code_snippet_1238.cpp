struct page *gfn_to_page(struct kvm *kvm, gfn_t gfn)
{
	pfn_t pfn;

	pfn = gfn_to_pfn(kvm, gfn);
	if (!pfn) {
		return NULL;
	}

	return kvm_pfn_to_page(pfn);
}