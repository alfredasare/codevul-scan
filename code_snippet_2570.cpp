u64 gf_net_get_ntp_ts()
{
	u64 res;
	u32 sec, frac;
	gf_net_get_ntp(&sec, &frac);
	if (sec >= (1ULL << 32) / 2) {
		// Handle error or return an appropriate value
		// to indicate an integer overflow
		return 0;
	}
	res = sec;
	res <<= 32;
	res |= frac;
	return res;
}