static struct file *userfaultfd_file_create(int flags)
{
    //...
    file = anon_inode_getfile("[userfaultfd]", &userfaultfd_fops, ctx,
                              O_RDWR | (flags & UFFD_SHARED_FCNTL_FLAGS));
    if (IS_ERR(file)) {
        mmdrop(ctx->mm);
        kmem_cache_free(userfaultfd_ctx_cachep, ctx);
        ctx->mm = NULL;
    }
    return file;
}