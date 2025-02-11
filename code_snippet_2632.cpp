void kvm\_free\_physmem(struct kvm \*kvm)
{
if (kvm->memslots && kvm->memslots->nmemslots > 0) {
int i;
struct kvm\_memslots \*slots = kvm->memslots;

for (i = 0; i < slots->nmemslots; ++i)
kvm\_free\_physmem\_slot(&slots->memslots[i], NULL);

kfree(kvm->memslots);
kvm->memslots = NULL;
}
}