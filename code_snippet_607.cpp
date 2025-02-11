l2tp_framing_cap_print(netdissect_options *ndo, const u_char *dat)
{
	const uint32_t *ptr = (const uint32_t *)dat;
	size_t dat_length = strlen((const char *)dat);

	if (dat_length < sizeof(uint32_t)) {
		return; // Early exit to avoid out-of-bounds read
	}

	if ((ptr + 1) > (const uint32_t *)((const char *)dat + dat_length)) {
		return; // Early exit to avoid out-of-bounds read
	}

	if (*ptr & L2TP_FRAMING_CAP_ASYNC_MASK) {
		ND_PRINT((ndo, "A"));
	}

	if (*ptr & L2TP_FRAMING_CAP_SYNC_MASK) {
		ND_PRINT((ndo, "S"));
	}
}