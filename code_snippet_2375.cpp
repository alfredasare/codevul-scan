struct ctl_table * __net_init ipv6_icmp_sysctl_init(struct net *net)
{
    struct ctl_table *table;

    if (!net) {
        printk(KERN_ERR "Invalid net structure\n");
        return NULL;
    }

    table = kmemdup(ipv6_icmp_table_template,
                    sizeof(ipv6_icmp_table_template),
                    GFP_KERNEL);

    if (table) {
        table[0].data = &net->ipv6.sysctl.icmpv6_time;
    }

    return table;
}