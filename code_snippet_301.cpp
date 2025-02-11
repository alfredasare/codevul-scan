static int __init init_inodecache(void)
{
    int size = sizeof(struct iso_inode_info);
    if (size > INT_MAX) {
        pr_err("Invalid size for isofs_inode_cache: %d\n", size);
        return -EINVAL;
    }

    isofs_inode_cachep = kmem_cache_create("isofs_inode_cache",
                                            sizeof(struct iso_inode_info),
                                            0, (SLAB_RECLAIM_ACCOUNT|SLAB_MEM_SPREAD),
                                            init_once);
    if (isofs_inode_cachep == NULL) {
        return -ENOMEM;
    }
    return 0;
}