static int handle_wbinvd(struct kvm_vcpu *vcpu)
{
    if (!vcpu) {
        return -EINVAL; 
    }

    int ret = kvm_emulate_wbinvd(vcpu);
    if (ret < 0) {
        // handle error return value
    }
    return ret;
}