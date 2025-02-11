SYSCALL_DEFINE1(inotify_init1, int, flags)
{
	struct fsnotify_group *group;
	struct user_struct *user;
	int ret;

	/* Check the IN_* constants for consistency.  */
	BUILD_BUG_ON(IN_CLOEXEC != O_CLOEXEC);
	BUILD_BUG_ON(IN_NONBLOCK != O_NONBLOCK);

	if (flags & ~(IN_CLOEXEC | IN_NONBLOCK))
		return -EINVAL;

	// Add an integer overflow check for 'atomic_read(&user->inotify_devs)' and 'flags'
	user = get_current_user();
	if (atomic_read(&user->inotify_devs) >= (inotify_max_user_instances - 1)) {
		return -EMFILE;
	}
	if ((atomic_read(&user->inotify_devs) + 1) < atomic_read(&user->inotify_devs)) {
		return -EOVERFLOW;
	}

	group = inotify_new_group(user, inotify_max_queued_events);
	if (IS_ERR(group)) {
		ret = PTR_ERR(group);
		goto out_free_uid;
	}

	atomic_inc(&user->inotify_devs);

	ret = anon_inode_getfd("inotify", &inotify_fops, group,
				  O_RDONLY | flags);
 	if (ret >= 0)
 		return ret;
 
 	atomic_dec(&user->inotify_devs);
 out_free_uid:
 	free_uid(user);
	return ret;
}