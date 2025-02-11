static ssize_t pages_to_scan_store(struct kobject *kobj,
				   struct kobj_attribute *attr,
				   const char *buf, size_t count)
{
	int err;
	unsigned long nr_pages;

	err = kstrtoul(buf, 10, &nr_pages, &count);
	if (err || nr_pages > UINT_MAX)
		return -EINVAL;

	if (nr_pages < 0)
		return -ERANGE;

	ksm_thread_pages_to_scan = nr_pages;

	return count;
}