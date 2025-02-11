static int stgi_interception(struct vcpu_svm *svm)
{
    int ret;

    ret = nested_svm_check_permissions(svm);
    if (ret!= 0) {
        disable_gif(svm);
        return ret;
    }

    svm->next_rip = kvm_rip_read(&svm->vcpu) + 3;
    ret = skip_emulated_instruction(&svm->vcpu);
    if (ret!= 0) {
        disable_gif(svm);
        return ret;
    }

    enable_gif(svm);

    return 1;
}