struct io_context *get_io_context(gfp_t gfp_flags, int node)
{
	struct io_context *ret = NULL;

	/*
	 * Check for unlikely race with exiting task. ioc ref count is
	 * zero when ioc is being detached.
	 */
	do {
		ret = current_io_context(gfp_flags, node);
		if (!ret)
			break;

		spin_lock(&ret->refcount_lock);
		if (atomic_long_inc_return(&ret->refcount) == 1) {
			spin_unlock(&ret->refcount_lock);
			break;
		}
		spin_unlock(&ret->refcount_lock);
	} while (1);

	return ret;
}