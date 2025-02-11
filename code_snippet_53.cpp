#define RPL_MASK 0x3

static void fix_pmode_seg(struct kvm_vcpu *vcpu, int seg,
                         struct kvm_segment *save)
{
    if (!emulate_invalid_guest_state) {
        if (seg == VCPU_SREG_CS || seg == VCPU_SREG_SS)
            save->selector &= ~RPL_MASK;

        save->dpl = save->selector & SELECTOR_DPL_MASK;
        save->s = (save->selector & SELECTOR_TYPE_MASK) == SELECTOR_TYPE_CS;
    }

    vmx_set_segment(vcpu, save, seg);
}