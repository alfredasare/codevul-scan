static void inode_lru_list_add(struct inode *inode)
{
    if (!inode ||!list_lru_add(&inode->i_sb->s_inode_lru, &inode->i_lru)) {
        return;
    }
    smp_wmb(); // Ensure visibility of updated counter
    this_cpu_inc(nr_unused);
}