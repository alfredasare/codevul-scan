sync_force_parallel_store(struct mddev *mddev, const char *buf, size_t len)
{
	unsigned long n;

	if (kstrtoul_from_user(buf, len, 10, &n))
		return -EINVAL;

	if (n > 1)
		return -ERANGE;

	mddev->parallel_resync = n;

	if (mddev->sync_thread)
		wake_up(&resync_wait);

	return len;
}