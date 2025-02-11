static void fix_pmode_seg(struct kvm_vcpu *vcpu, int seg, struct kvm_segment *save)
{
	const int rpl_mask = SELECTOR_RPL_MASK;

	if (!emulate_invalid_guest_state) {
		if (seg == VCPU_SREG_CS || seg == VCPU_SREG_SS) {
			save->selector &= ~rpl_mask;
			save->selector |= (save->dpl & rpl_mask);
		}
		save->s = 1;
	}
	vmx_set_segment(vcpu, save, seg);
}