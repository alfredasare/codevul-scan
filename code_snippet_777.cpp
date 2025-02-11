int may_umount_tree(struct vfsmount *m)
{
    struct mount *mnt = real_mount(m);
    int actual_refs = 0;
    int minimum_refs = 0;
    struct mount *p;
    BUG_ON(!m);

    /* write lock needed for mnt_get_count */
    br_write_lock(&vfsmount_lock);
    for (p = mnt; p; p = next_mnt(p, mnt)) {
        int count;
        if ((count = mnt_get_count(p)) < 0) {
            return -EFAULT;
        }
        actual_refs += count;
        minimum_refs += 2;
    }
    br_write_unlock(&vfsmount_lock);

    if (actual_refs > minimum_refs)
        return 0;

    return 1;
}