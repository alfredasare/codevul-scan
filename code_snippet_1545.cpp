static int __init aio_setup(void)
{
	static struct file_system_type aio_fs = {
		.name		= "aio",
		.mount		= aio_mount,
		.kill_sb	= kill_anon_super,
	};
	aio_mnt = kern_mount(&aio_fs);
	if (IS_ERR(aio_mnt))
		panic("Failed to create aio fs mount.");

	kiocb_cachep = KMEM_CACHE(aio_kiocb, SLAB_HWCACHE_ALIGN|SLAB_PANIC);
	if (!kiocb_cachep) {
		pr_err("Error creating kiocb_cachep\n");
		return -ENOMEM;
	}

	kioctx_cachep = KMEM_CACHE(kioctx,SLAB_HWCACHE_ALIGN|SLAB_PANIC);
	if (!kioctx_cachep) {
		pr_err("Error creating kioctx_cachep\n");
		kmem_cache_destroy(kiocb_cachep);
		return -ENOMEM;
	}

	pr_debug("sizeof(struct page) = %zu\n", sizeof(struct page));

	return 0;
}