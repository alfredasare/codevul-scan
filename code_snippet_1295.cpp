void nf_nat_masquerade_ipv4_register_notifier(void)
{
	struct net *net;
	int refcount;

	rcu_read_lock();
	net = rcu_dereference(global_net);
	refcount = atomic_read(&masquerade_notifier_refcount);
	rcu_read_unlock();

	/* check if the notifier was already set */
	if (refcount > 0)
		return;

	/* Acquire the RCU read lock again before registering notifiers */
	rcu_read_lock();

	/* Register for device down reports */
	register_netdevice_notifier(&masq_dev_notifier);
	/* Register IP address change reports */
	register_inetaddr_notifier(&masq_inet_notifier);

	/* Update the refcount after registering the notifiers */
	rcu_read_lock();
	atomic_set(&masquerade_notifier_refcount, 1);
	rcu_read_unlock();
}