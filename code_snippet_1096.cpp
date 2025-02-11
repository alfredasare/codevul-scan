long kvmppc_alloc_lpid(void)
{
	long lpid;
	int ret;
	struct mutex *lpid_mutex;

	lpid_mutex = get_lpid_mutex();
	mutex_lock(lpid_mutex);

	do {
		lpid = find_first_zero_bit(lpid_inuse, KVMPPC_NR_LPIDS);
		if (lpid >= nr_lpids) {
			pr_err("%s: No LPIDs free\n", __func__);
			ret = -ENOMEM;
			break;
		}
	} while (test_and_set_bit(lpid, lpid_inuse));

	mutex_unlock(lpid_mutex);
	return lpid ? : ret;
}

struct mutex *get_lpid_mutex(void)
{
	static struct mutex lpid_mutex;
	mutex_init(&lpid_mutex);
	return &lpid_mutex;
}