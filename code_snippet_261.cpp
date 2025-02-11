static ssize_t hash_sendpage(struct socket *sock, struct page *page,
			     int offset, size_t size, int flags)
{
    //...

    err = af_alg_wait_for_completion(err, &ctx->completion);
    if (err) {
        printk(KERN_ERR "hash_sendpage: Error %d occurred\n", err);
        goto unlock;
    }

    //...
}