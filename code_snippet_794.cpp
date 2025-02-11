static DEFINE_MUTEX(pit_mutex);

int pit_has_pending_timer(struct kvm_vcpu *vcpu)
{
	struct kvm_pit *pit = vcpu->kvm->arch.vpit;
	int pending = 0;

	mutex_lock(&pit_mutex);

	if (pit && kvm_vcpu_is_bsp(vcpu) && pit->pit_state.irq_ack)
		pending = atomic_read(&pit->pit_state.pit_timer.pending);

	mutex_unlock(&pit_mutex);

	return pending;
}