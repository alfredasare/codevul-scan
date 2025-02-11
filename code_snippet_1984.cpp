void llc_sysctl_exit(void)
{
    if (llc2_timeout_header) {
        unregister_net_sysctl_table(llc2_timeout_header);
        llc2_timeout_header = NULL;
        memset(&llc2_timeout_header, 0, sizeof(*llc2_timeout_header));
    }
    if (llc_station_header) {
        unregister_net_sysctl_table(llc_station_header);
        llc_station_header = NULL;
        memset(&llc_station_header, 0, sizeof(*llc_station_header));
    }
}