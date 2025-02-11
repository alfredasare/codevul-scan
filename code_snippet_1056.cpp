code:


static void aio_free_ring(struct kioctx *ctx)
{
    int i;

    for (i = 0; i < ctx->nr_pages; i++) {
        int ret;

        ret = put_page(ctx->ring_pages[i]);
        if (ret) {
            printk(KERN_ERR "aio_free_ring: put_page failed (%d)\n");
            return;
        }
        pr_debug("pid(%d) [%d] page->count=%d\n", current->pid, i, page_count(ctx->ring_pages[i]));
    }

    int ret2 = put_aio_ring_file(ctx);
    if (ret2) {
        printk(KERN_ERR "aio_free_ring: put_aio_ring_file failed (%d)\n");
        return;
    }

    if (ctx && ctx->ring_pages && ctx->ring_pages!= ctx->internal_pages) {
        kfree(ctx->ring_pages);
    }
}