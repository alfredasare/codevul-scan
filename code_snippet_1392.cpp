static void kvmclock_reset(struct kvm_vcpu *vcpu)
{
	struct kvm_time_caches *tc = &vcpu->arch.time_caches;
	unsigned long flags;

	raw_spin_lock_irqsave(&vcpu->lock, flags);

	if (vcpu->arch.time_page &&
	    cmpxchg(&vcpu->arch.time_page, vcpu->arch.time_page,
		    NULL, atomic_dec_and_test)) {
		kvm_release_page_dirty(vcpu->arch.time_page);
	}

	tc->last_ck = ktime_get_real();
	tc->last_wall = ktime_get();

	raw_spin_unlock_irqrestore(&vcpu->lock, flags);
}