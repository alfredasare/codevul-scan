SYSCALL_DEFINE3(inotify_add_watch, int, fd, const char __user *, pathname, _u32, mask)
{
    struct fsnotify_group *group;
    struct inode *inode;
    struct path path;
    struct file *filp;
    int ret, fput_needed;
    unsigned flags = 0;

    filp = fget_light(fd, &fput_needed);
    if (filp == NULL) {
        ret = -EBADF;
        goto fput_and_out;
    }

    /* verify that this is indeed an inotify instance */
    if (unlikely(filp->f_op!= &inotify_fops)) {
        ret = -EINVAL;
        goto fput_and_out;
    }

    if (!(mask & IN_DONT_FOLLOW))
        flags |= LOOKUP_FOLLOW;
    if (mask & IN_ONLYDIR)
        flags |= LOOKUP_DIRECTORY;

    ret = inotify_find_inode(pathname, &path, flags);
    if (ret)
        goto fput_and_out;

    inode = path.dentry->d_inode;
    group = filp->private_data;

    /* create/update an inode mark */
    ret = inotify_update_watch(group, inode, mask);
    path_put(&path);
fput_and_out:
    fput_light(filp, fput_needed);
    return ret;
}