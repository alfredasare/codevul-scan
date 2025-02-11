set_vrrp_defaults(data_t * data)
{
	// ... previous code ...

	strncpy(data->vrrp_iptables_inchain, "INPUT", sizeof(data->vrrp_iptables_inchain) - 1);
#ifdef _HAVE_LIBIPSET_
	strncpy(data->vrrp_ipset_address, "keepalived", sizeof(data->vrrp_ipset_address) - 1);
	strncpy(data->vrrp_ipset_address6, "keepalived6", sizeof(data->vrrp_ipset_address6) - 1);
	strncpy(data->vrrp_ipset_address_iface6, "keepalived_if6", sizeof(data->vrrp_ipset_address_iface6) - 1);
#endif

	// ... remaining code ...
}