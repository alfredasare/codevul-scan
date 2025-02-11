static int proc_sys_delete(const struct dentry *dentry)
{
    if (!dentry ||!dentry->d_inode) {
        return -EINVAL; 
    }
    return!!PROC_I(d_inode(dentry))->sysctl->unregistering;
}