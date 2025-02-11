static int do_siocgstampns(struct net *net, struct socket *sock,
			   unsigned int cmd, void __user *up)
{
	mm_segment_t old_fs = get_fs();
	struct timespec kts;
	int err;

	if (cmd >= SOCK_IOC_MAX || cmd < 0) {
		err = -EINVAL;
		goto out;
	}

	err = sock_do_ioctl_validate(net, sock, cmd);
	if (err)
		return err;

	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
	if (!err)
		err = compat_put_timespec(up, &kts);

	return err;

out:
	printk(KERN_WARNING "Invalid cmd %u\n", cmd);
	return err;
}