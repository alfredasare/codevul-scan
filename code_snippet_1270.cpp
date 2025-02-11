struct fib6_table *fib6_new_table(struct net *net, u32 id)
{
    struct fib6_table *tb;

    if (id > RT6_TABLE_MAX) {
        id = RT6_TABLE_MAIN; // Default value if id is invalid
    }

    tb = fib6_get_table(net, id);
    if (tb)
        return tb;

    tb = fib6_alloc_table(net, id);
    if (tb)
        fib6_link_table(net, tb);

    return tb;
}