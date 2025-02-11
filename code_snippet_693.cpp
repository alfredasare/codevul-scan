int kvm\_arch\_prepare\_memory\_region(struct kvm *kvm,
 struct kvm\_memory\_slot \*memslot,
 struct kvm\_memory\_slot old,
 struct kvm\_userspace\_memory\_region \*mem,
 int user\_alloc)
{
 unsigned long i;
 unsigned long pfn;
 int npages = memslot->npages;
 unsigned long base\_gfn = memslot->base\_gfn;

 if (base\_gfn + npages > (KVM\_MAX\_MEM\_SIZE >> PAGE\_SHIFT))
 return -ENOMEM;

 if (npages > (KVM\_MAX\_MEM\_SIZE >> PAGE\_SHIFT) - base\_gfn) {
 /* Integer overflow protection */
 return -ENOMEM;
 }

 for (i = 0; i < npages; i++) {
 pfn = gfn\_to\_pfn(kvm, base\_gfn + i);
 if (!kvm\_is\_mmio\_pfn(pfn)) {
 kvm\_set\_pmt\_entry(kvm, base\_gfn + i,
 pfn << PAGE\_SHIFT,
 \_PAGE\_AR\_RWX | \_PAGE\_MA\_WB);
 memslot->rmap[i] = (unsigned long)pfn\_to\_page(pfn);
 } else {
 kvm\_set\_pmt\_entry(kvm, base\_gfn + i,
 GPFN\_PHYS\_MMIO | (pfn << PAGE\_SHIFT),
 \_PAGE\_MA\_UC);
 memslot->rmap[i] = 0;
 }
 }

 return 0;
}