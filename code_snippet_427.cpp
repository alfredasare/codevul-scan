int __init nfc_genl_init(void)
{
	struct genl_family *nf_family;
	int rc;

	nf_family = genl_ctrl_alloc();
	if (!nf_family)
		return -ENOMEM;

	rc = genl_ctrl_resolve(nf_family);
	if (rc < 0) {
		genl_ctrl_put(nf_family);