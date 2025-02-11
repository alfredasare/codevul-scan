SYSCALL_DEFINE1(inotify_init1, int, flags)
{
    struct fsnotify_group *group;
    struct user_struct *user;
    int ret;

    /* Check the IN_* constants for consistency.  */
    BUILD_BUG_ON(IN_CLOEXEC!= O_CLOEXEC);
    BUILD_BUG_ON(IN_NONBLOCK!= O_NONBLOCK);

    if (flags & ~(IN_CLOEXEC | IN_NONBLOCK))
        return -EINVAL;

    user = get_current_user();
    mutex_lock(&user->inotify_devs_mutex);
    if (atomic_read(&user->inotify_devs) >= inotify_max_user_instances) {
        ret = -EMFILE;
        goto out_unlock;
    }
    atomic_inc(&user->inotify_devs);
    mutex_unlock(&user->inotify_devs_mutex);

    group = inotify_new_group(user, inotify_max_queued_events);
    if (IS_ERR(group)) {
        ret = PTR_ERR(group);
        atomic_dec(&user->inotify_devs);
        goto out;
    }

    ret = anon_inode_getfd("inotify", &inotify_fops, group, O_RDONLY | flags);
    if (ret >= 0)
        return ret;

    atomic_dec(&user->inotify_devs);
out:
    free_uid(user);
    return ret;
out_unlock:
    mutex_unlock(&user->inotify_devs_mutex);
    return ret;
}