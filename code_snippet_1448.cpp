static void *mntns_get(struct task_struct *task)
{
	struct mnt_namespace *ns = NULL;
	struct nsproxy *nsproxy;

	rcu_read_lock();
	nsproxy = task_nsproxy(task);
	if (nsproxy && (ns = nsproxy->mnt_ns)) {
		get_mnt_ns(ns);
	} else {
		printk(KERN_ERR "Null mnt_namespace encountered\n");
		rcu_read_unlock();
		return NULL;
	}

	return ns;
}