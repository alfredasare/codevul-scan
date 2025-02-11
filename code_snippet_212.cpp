static long convert(long val, int oldsgnd, int oldprec, int newsgnd, int newprec)
{
	if (newsgnd != oldsgnd) {
	}
	if (newprec != oldprec) {
		int shift\_amount = newprec - oldprec;
		if (shift\_amount < 0) {
			shift\_amount = -shift\_amount;
		}
		if (shift\_amount > 0 && shift\_amount > sizeof(val) \* 8) {
			// Handle error
			return -1;
		}
		if (newprec > oldprec) {
			val <<= shift\_amount;
		} else if (oldprec > newprec) {
			val >>= oldprec - newprec;
		}
	}
	return val;
}