static int pmcraid_netlink_init(void)
{
    int result;

    result = genl_register_family(&pmcraid_event_family);

    if (result)
        return result;

    if (current_uid() == 0 || cap_get_cap_net_raw_ioctl()) {
        pmcraid_info("registered NETLINK GENERIC group: %d\n", pmcraid_event_family.id);
    }

    return result;
}