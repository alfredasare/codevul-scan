int pit_has_pending_timer(struct kvm_vcpu *vcpu)
{
    struct kvm_pit *pit = vcpu->kvm->arch.vpit;
    struct kvm_pit_state *pit_state = &pit->pit_state;

    if (pit && kvm_vcpu_is_bsp(vcpu) && pit_state && pit_state->irq_ack)
        return atomic_read(&pit_state->pit_timer.pending);
    return 0;
}