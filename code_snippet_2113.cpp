static struct nd_opt_hdr *ndisc_next_option(struct nd_opt_hdr *cur,
					    struct nd_opt_hdr *end)
{
	int type;
	if (!cur ||!end || cur >= end)
		return NULL;

	type = cur->nd_opt_type;
	do {
		if (cur->nd_opt_len > sizeof(*cur) / sizeof(cur->nd_opt_hdr)) {
			return NULL;
		}

		cur = (struct nd_opt_hdr *)((char *)cur + (cur->nd_opt_len << 3));
		if (cur >= end || cur->nd_opt_type!= type) {
			break;
		}
	} while (1);

	return cur <= end && cur->nd_opt_type == type? cur : NULL;
}