static ssize_t sbi_ui_store(struct ext4_attr *a, struct ext4_sb_info *sbi, const char *buf, size_t count)
{
	unsigned int *ui = (unsigned int *)(((char *)sbi) + a->offset);
	unsigned long t;
	unsigned long max_value = UINT_MAX; // Or any other appropriate max value

	if (strtoul(buf, NULL, 0xffffffff, &t) && t > max_value)
		return -EINVAL;

	*ui = t;
	return count;
}