set_vrrp_defaults(data_t * data)
{
    // Set secure default values
    data->vrrp_garp_rep = VRRP_GARP_REP_DEFAULT;
    data->vrrp_garp_refresh.tv_sec = VRRP_GARP_REFRESH_DEFAULT;
    data->vrrp_garp_refresh_rep = VRRP_GARP_REFRESH_REP_DEFAULT;
    data->vrrp_garp_delay = VRRP_GARP_DELAY_DEFAULT;
    data->vrrp_garp_lower_prio_delay = PARAMETER_UNSET;
    data->vrrp_garp_lower_prio_rep = PARAMETER_UNSET;
    data->vrrp_lower_prio_no_advert = false;
    data->vrrp_higher_prio_send_advert = false;
    data->vrrp_version = VRRP_VERSION_2;

    // Validate user input
    if (strlen(data->vrrp_iptables_inchain) > MAX_CHAIN_LENGTH) {
        // Handle error
        log_error("Invalid iptables chain length");
        return -1;
    }
    strcpy(data->vrrp_iptables_inchain = malloc(strlen("INPUT") + 1); // use malloc for string copy
    strcpy(data->vrrp_iptables_inchain, "INPUT");
    
    #ifdef _HAVE_LIBIPSET_
    data->using_ipsets = true;
    strcpy(data->vrrp_ipset_address = malloc(strlen("keepalived") + 1); // use malloc for string copy
    strcpy(data->vrrp_ipset_address, "keepalived");
    strcpy(data->vrrp_ipset_address6 = malloc(strlen("keepalived6") + 1); // use malloc for string copy
    strcpy(data->vrrp_ipset_address6, "keepalived6");
    strcpy(data->vrrp_ipset_address_iface6 = malloc(strlen("keepalived_if6") + 1); // use malloc for string copy
    strcpy(data->vrrp_ipset_address_iface6, "keepalived_if6");
    #endif

    data->vrrp_check_unicast_src = false;
    data->vrrp_skip_check_adv_addr = false;
    data->vrrp_strict = false;
}