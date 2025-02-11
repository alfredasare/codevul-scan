int __remove_suid(struct dentry *dentry, int kill)
{
    struct iattr newattrs;

    if (kill < 0 || kill > 1) {
        printk(KERN_ERR "Invalid kill value: %d\n");
        return -EINVAL;
    }

    if (!dentry ||!dentry->d_inode) {
        printk(KERN_ERR "Invalid dentry pointer\n");
        return -EBADF;
    }

    newattrs.ia_valid = ATTR_FORCE | (kill == 1);
    return notify_change(dentry, &newattrs);
}