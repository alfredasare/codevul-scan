static int __init init_inodecache(void)
{
	isofs_inode_cachep = kmem_cache_create("isofs_inode_cache",
					sizeof(struct iso_inode_info),
					0, SLAB_HWCACHE_ALIGN,
					init_once);
	if (isofs_inode_cachep == NULL)
		return -ENOMEM;
	return 0;
}