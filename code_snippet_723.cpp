static inline int check_target(struct arpt_entry *e, const char *name)
{
	size_t max_table_length = sizeof(par.table);
	if (strlen(name) >= max_table_length) {
		duprintf("arp_tables: Invalid table name length.\n");
		return -EINVAL;
	}

	struct xt_entry_target *t = arpt_get_target(e);
	int ret;
	struct xt_tgchk_param par = {
		.table     = name,
		.entryinfo = e,
		.target    = t->u.kernel.target,
		.targinfo  = t->data,
		.hook_mask = e->comefrom,
		.family    = NFPROTO_ARP,
	};

	ret = xt_check_target(&par, t->u.target_size - sizeof(*t), 0, false);
	if (ret < 0) {
		duprintf("arp_tables: check failed for `%s'.\n",
			 t->u.kernel.target->name);
		return ret;
	}
	return 0;
}