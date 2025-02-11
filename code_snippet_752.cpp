int hns_rcb_set_coalesce_usecs(
	struct rcb_common_cb *rcb_common, u32 port_idx, u32 timeout)
{
	u32 old_timeout = hns_rcb_get_coalesce_usecs(rcb_common, port_idx);
	u32 validated_timeout = timeout;

	if (timeout > HNS_RCB_MAX_COALESCED_USECS) {
		validated_timeout = HNS_RCB_MAX_COALESCED_USECS;
	} else if (timeout < 1) {
		validated_timeout = 1; // Set to the minimum allowed value
	}

	if (timeout!= validated_timeout)
		return -EINVAL;

	//... (rest of the code remains the same)