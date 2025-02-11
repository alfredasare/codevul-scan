int cap_ptrace_access_check(struct task_struct *child, unsigned int mode)
{
	int ret = 0;
	const struct cred *cred, *child_cred;
	bool equal_namespaces;

	rcu_read_lock();
	cred = current_cred();
	child_cred = __task_cred(child);
	equal_namespaces = (cred->user->user_ns == child_cred->user->user_ns);
	if (equal_namespaces && cap_issubset(child_cred->cap_permitted, cred->cap_permitted))
		goto out;
	if (!equal_namespaces && ns_capable(child_cred->user->user_ns, CAP_SYS_PTRACE))
		goto out;
	ret = -EPERM;
out:
	rcu_read_unlock();
	return ret;
}