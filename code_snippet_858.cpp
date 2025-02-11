static int kvm_dev_ioctl_create_vm(unsigned long type)
{
	int r;
	struct kvm *kvm;
	struct file *file;

	kvm = kvm_create_vm(type);
	if (IS_ERR(kvm))
		return PTR_ERR(kvm);
#ifdef CONFIG_KVM_MMIO
	r = kvm_coalesced_mmio_init(kvm);
	if (r < 0)
		goto put_kvm;
#endif
	r = get_kvm_vm_file(kvm, &fd);
	if (r < 0)
		goto put_kvm;

	if (kvm_create_vm_debugfs(kvm, fd) < 0) {
		put_unused_fd(fd);
		fput(file);
		return -ENOMEM;
	}
	kvm_uevent_notify_change(KVM_EVENT_CREATE_VM, kvm);

	fd_install(fd, file);
	return fd;

put_kvm:
	kvm_put_kvm(kvm);
	return r;
}

static int get_kvm_vm_file(struct kvm *kvm, int *fd)
{
	int r, new_fd;

	r = get_unused_fd_flags(O_CLOEXEC);
	if (r < 0)
		return r;

	new_fd = r;

	r = anon_inode_getfile("kvm-vm", &kvm_vm_fops, kvm, O_RDWR, new_fd);
	if (r < 0) {
		put_unused_fd(new_fd);
		return r;
	}

	*fd = new_fd;
	return 0;
}