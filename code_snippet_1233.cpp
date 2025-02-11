static void nfnl_err_del(struct nfnl_err *nfnl_err)
{
    size_t size = offsetof(struct nfnl_err, head) + sizeof(list_head);
    if (offsetof(struct nfnl_err, head) + sizeof(list_head) <= sizeof(*nfnl_err)) {
        list_del(&nfnl_err->head);
        kfree(nfnl_err);
    } else {
        printk(KERN_ERR "Error: buffer too small\n");
    }
}