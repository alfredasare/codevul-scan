void llc_sysctl_exit(void)
{
	if (llc2_timeout_header && is_valid_pointer(llc2_timeout_header)) {
		unregister_net_sysctl_table(llc2_timeout_header);
		llc2_timeout_header = NULL;
	}
	if (llc_station_header && is_valid_pointer(llc_station_header)) {
		unregister_net_sysctl_table(llc_station_header);
		llc_station_header = NULL;
	}
}

// Add the is_valid_pointer function to check if the pointer is valid before dereferencing it.
bool is_valid_pointer(const void *ptr)
{
	return ptr != NULL;
}