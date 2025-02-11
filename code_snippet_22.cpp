static int pmcraid_netlink_init(void)
{
	int result;
	struct genl_family *family = &pmcraid_event_family;

	result = genl_register_family(family);

	if (result)
		goto exit_unregister_family;

	pmcraid_info("registered NETLINK GENERIC group: %d\n", family->id);

exit_unregister_family:
	if (result && family->id)
		genl_unregister_family(family);

	return result;
}