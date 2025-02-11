static int posix_get_monotonic_coarse(clockid_t which_clock,
									  struct timespec64 *tp)
{
	if (which_clock > CLOCK_MAX || which_clock < CLOCK_MIN) {
		return -EINVAL;
	}

	*tp = get_monotonic_coarse64(which_clock);
	return 0;
}