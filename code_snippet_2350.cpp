static void unregister_pernet_operations(struct pernet_operations *ops)
{
    __unregister_pernet_operations(ops);
    rcu_barrier();
    if (ops->id) {
        int id = *ops->id;
        if (ida_remove(&net_generic_ids, id) < 0) {
            printk(KERN_ERR "Error removing IDA entry\n");
        }
    }
}