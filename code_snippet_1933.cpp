static u64 dccp_ack_seq(const struct dccp_hdr *dh)
{
	const struct dccp_hdr_ack_bits *dhack;
	u64 high, low, result;

	dhack = (void *)dh + __dccp_basic_hdr_len(dh);
	high = ntohs(dhack->dccph_ack_nr_high);
	low = ntohl(dhack->dccph_ack_nr_low);

	if (high > UINT32_MAX || low > UINT32_MAX) {
		// Handle error
		return 0;
	}

	result = ((u64)high << 32) + low;
	return result;
}