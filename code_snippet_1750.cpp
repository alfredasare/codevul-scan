exp_build_l4proto_sctp(const struct nf_conntrack *ct, struct nethdr *n, int a)
{
	struct nfct_attr_grp_port grp = {0};
	size_t size = sizeof(struct nfct_attr_grp_port);

	if (size > a)
		size = a;

	ct_build_group(ct, ATTR_GRP_ORIG_PORT, n, size, &grp);
}