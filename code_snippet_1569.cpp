struct cred *prepare_creds(void)
{
	struct task_struct *task = current;
	const struct cred *old;
	struct cred *new;

	if (!task || !task->cred)
		return NULL;

	validate_process_creds();

	new = kmem_cache_alloc(cred_jar, GFP_KERNEL);
	if (!new)
		return NULL;

	kdebug("prepare_creds() alloc %p", new);

	old = task->cred;
	if (!memcpy(new, old, sizeof(struct cred))) {
		kfree(new);
		return NULL;
	}

	atomic_set(&new->usage, 1);
	set_cred_subscribers(new, 0);
	if (!get_group_info(new->group_info)) {
		kfree(new);
		return NULL;
	}
	if (!get_uid(new->user)) {
		kfree(new->group_info);
		kfree(new);
		return NULL;
	}

#ifdef CONFIG_KEYS
	if (!key_get(new->thread_keyring) || !key_get(new->request_key_auth)) {
		put_uid(new->user);
		kfree(new->group_info);
		kfree(new);
		return NULL;
	}
	atomic_inc(&new->tgcred->usage);
#endif

#ifdef CONFIG_SECURITY
	new->security = NULL;
#endif

	if (security_prepare_creds(new, old, GFP_KERNEL) < 0) {
		put_uid(new->user);
		kfree(new->group_info);
		kfree(new);
		return NULL;
	}
	validate_creds(new);
	return new;
}