static void f2fs_i_callback(struct rcu_head *head)
{
    struct inode *inode = container_of(head, struct inode, i_rcu);
    int idx = (F2FS_I(inode)->i_flags & F2FS_INODE_FLAG_MASK) % F2FS_INODE_FLAG_MAX;

    if (idx >= 0) {
        kmem_cache_free(f2fs_inode_cachep, F2FS_I(inode));
    } else {
        printk(KERN_ERR "f2fs: Invalid index value %d\n", idx);
    }
}