static int kvm_dev_ioctl_create_vm(unsigned long type)
{
    int r;
    struct kvm *kvm;
    struct file *file;

    kvm = kvm_create_vm(type);
    if (IS_ERR(kvm)) {
        return PTR_ERR(kvm);
    }

    r = kvm_coalesced_mmio_init(kvm);
    if (r < 0) {
        kvm_put_kvm(kvm);
        return r;
    }

    r = get_unused_fd_flags(O_CLOEXEC);
    if (r < 0) {
        kvm_put_kvm(kvm);
        return r;
    }

    file = anon_inode_getfile("kvm-vm", &kvm_vm_fops, kvm, O_RDWR);
    if (IS_ERR(file)) {
        put_unused_fd(r);
        r = PTR_ERR(file);
        kvm_put_kvm(kvm);
        return r;
    }

    // Rest of the code...

    if (kvm_create_vm_debugfs(kvm, r) < 0) {
        fput(file);
        kvm_put_kvm(kvm);
        return -ENOMEM;
    }

    kvm_uevent_notify_change(KVM_EVENT_CREATE_VM, kvm);

    fd_install(r, file);
    return r;
}