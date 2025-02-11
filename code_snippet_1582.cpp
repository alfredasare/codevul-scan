static int cdrom_is_random_writable(struct cdrom_device_info *cdi, int *write)
{
	struct rwrt_feature_desc rfd;
	int ret;

	*write = 0;

	if ((ret = cdrom_get_random_writable(cdi, &rfd)))
		return ret;

        // Validate the input data's length before using be16_to_cpu
	if (sizeof(rfd.feature_code) != 2) {
		ret = -EINVAL;
		goto out;
	}

	if (CDF_RWRT == be16_to_cpu(rfd.feature_code))
		*write = 1;

out:
	return ret;
}