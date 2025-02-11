set_interface_reachtime(const char *iface, uint32_t rtime)
{
    int ret;
    const char *allowed_interfaces[] = {"eth0", "eth1", "wlan0"}; // Whitelist of allowed interfaces
    size_t num_allowed_interfaces = sizeof(allowed_interfaces) / sizeof(*allowed_interfaces);

    if (privsep_enabled())
        return privsep_interface_reachtime(iface, rtime);

    for (size_t i = 0; i < num_allowed_interfaces; i++) {
        if (strcmp(iface, allowed_interfaces[i]) == 0) {
            ret = set_interface_var(iface,
                    PROC_SYS_IP6_BASEREACHTIME_MS,
                    NULL,
                    rtime);
            if (ret)
                ret = set_interface_var(iface,
                        PROC_SYS_IP6_BASEREACHTIME,
                        "BaseReachableTimer",
                        rtime / 1000); /* sec */
            return ret;
        }
    }
    return -EINVAL;
}