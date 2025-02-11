static int __init aio_setup(void)
{
   ...
    pr_debug("sizeof(struct page) = %zu\n", sizeof(struct page));
    if (sizeof(struct page) > PAGE_SIZE) {
        pr_debug("sizeof(struct page) exceeds PAGE_SIZE");
        return -EINVAL;
    }
   ...
}