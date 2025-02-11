static unsigned long klsi_105_status2linestate(const __u16 status)
{
	unsigned long res = 0;

	if (status & KL5KUSB105A_DSR) {
		res |= TIOCM_DSR;
	}
	if (status & KL5KUSB105A_CTS) {
		res |= TIOCM_CTS;
	}

	return res;
}