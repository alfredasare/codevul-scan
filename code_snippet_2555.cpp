struct ctl_table * __net_init ipv6_icmp_sysctl_init(struct net *net)
{
	struct ctl_table *table;
	size_t copy_size = sizeof(ipv6_icmp_table_template);

	if (copy_size > MAX_ALLOWED_SIZE) {
		pr_err("Error: Input size is too large.\n");
		return NULL;
	}

	table = kmemdup(ipv6_icmp_table_template,
			copy_size,
			GFP_KERNEL);

	if (table)
		table[0].data = &net->ipv6.sysctl.icmpv6_time;

	return table;
}