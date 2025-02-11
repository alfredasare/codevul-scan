int kvm\_write\_guest\_cached(struct kvm \*kvm, struct gfn\_to\_hva\_cache \*ghc,
void \*data, unsigned long len)
{
struct kvm\_memslots \*slots = kvm\_memslots(kvm);
int r;

BUG\_ON(len > ghc->len);

if (slots->generation != ghc->generation) {
kvm\_gfn\_to\_hva\_cache\_init(kvm, ghc, ghc->gpa, ghc->len);
return -EINVAL;
}

if (unlikely(!ghc->memslot))
return kvm\_write\_guest(kvm, ghc->gpa, data, len);

if (kvm\_is\_error\_hva(ghc->hva))
return -EFAULT;

mutex\_lock(&kvm->slots\_mutex);
r = __copy\_to\_user((void __user \*)ghc->hva, data, len);
if (r)
mutex\_unlock(&kvm->slots\_mutex);
return -EFAULT;

mark\_page\_dirty\_in\_slot(ghc->memslot, ghc->gpa >> PAGE\_SHIFT);
mutex\_unlock(&kvm->slots\_mutex);

return 0;
}

In order to fix the TOCTOU vulnerability, we need to ensure that the memory slot's state remains unchanged between the check (checking the slot's generation) and the use (writing to the user memory). To achieve this, we acquire the `kvm->slots_mutex` lock before copying data to the user memory, and release the lock after completing the operation. This way, no other thread can modify the memory slot while we are performing the copy, thus eliminating the race condition.

Note that we also return `-EINVAL` instead of continuing with the write operation if the slot's generation has changed. This is a more appropriate error code, as it indicates an unexpected change in the memory slots, which could be due to a race condition or other synchronization issues.