void __init anon_vma_init(void)
{
    unsigned int size = sizeof(struct anon_vma);

    anon_vma_cachep = kmem_cache_create("anon_vma", size,
            0, SLAB_HWCACHE_ALIGN, anon_vma_ctor);

    size = sizeof(struct anon_vma_chain);
    anon_vma_chain_cachep = kmem_cache_create("anon_vma_chain", size,
            0, SLAB_HWCACHE_ALIGN, NULL);
}