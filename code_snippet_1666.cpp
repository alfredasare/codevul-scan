static void rose_kill_by_device(struct net_device *dev)
{
	struct sock *s;

	if (!dev) {
		pr_err("Invalid device pointer\n");
		return;
	}

	spin_lock_bh(&rose_list_lock);
	sk_for_each(s, &rose_list) {
		struct rose_sock *rose = rose_sk(s);

		if (!rose || rose->device != dev)
			continue;

		rose_disconnect(s, ENETUNREACH, ROSE_OUT_OF_ORDER, 0);