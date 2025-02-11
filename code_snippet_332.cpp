int do_migrate_pages(struct mm_struct *mm,
	const nodemask_t *from_nodes, const nodemask_t *to_nodes, int flags)
{
	int node, ret = 0;

	if (!mm || !from_nodes || !to_nodes)
		return -EINVAL;

	for_each_node(node) {
		if (!(from_nodes->bits[node / BITS_PER_LONG] & (1UL << (node % BITS_PER_LONG))))
			continue;

		ret = migrate_pages(mm, from_nodes, to_nodes, node, flags);
		if (ret)
			break;
	}

	return ret;
}