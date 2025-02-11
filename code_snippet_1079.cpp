void ebt_unregister_table(struct net *net, struct ebt_table *table,
			  const struct nf_hook_ops *ops)
{
    if (ops) {
        size_t num_hooks = hweight32(table->valid_hooks);
        if (num_hooks > NF_HOOK_MAX) {
            /* Handle error case */
            return;
        }
        nf_unregister_net_hooks(net, ops, num_hooks);
    }
    __ebt_unregister_table(net, table);
}