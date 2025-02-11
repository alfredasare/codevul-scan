static void pmcraid_internal_done(struct pmcraid_cmd *cmd)
{
	if (!cmd) {
		pr_err("%s: NULL pointer\n", __func__);