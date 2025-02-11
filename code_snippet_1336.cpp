static void svm_set_cr3(struct kvm_vcpu *vcpu, unsigned long root)
{
    struct vcpu_svm *svm = to_svm(vcpu);

    root = sanitize_input(root);

    svm->vmcb->save.cr3 = root;
    mark_dirty(svm->vmcb, VMCB_CR);
    svm_flush_tlb(vcpu);
}

unsigned long sanitize_input(unsigned long input)
{
    const char *allowed_chars = "0123456789abcdef";
    unsigned long sanitized_input = 0;

    for (int i = 0; i < sizeof(input); i++) {
        char c = (char)(input >> (i * 8));
        if (strchr(allowed_chars, c)) {
            sanitized_input |= (c << (i * 8));
        }
    }

    return sanitized_input;
}