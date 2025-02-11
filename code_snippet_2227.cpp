static void good_flp_intr(void)
{
	int err_count;

	if (probing) {
		DRS->probed_format++;