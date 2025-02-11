static int store_max_write_buffer_kb(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct comedi_device_file_info *info = dev_get_drvdata(dev);
	unsigned long new_max_size_kb;
	uint64_t new_max_size;
	const uint64_t max_size_limit = UINT64_MAX / bytes_per_kibi;
	struct comedi_subdevice *const write_subdevice =
		comedi_get_write_subdevice(info);

	if (strict_strtoul(buf, 10, &new_max_size_kb))
		return -EINVAL;
	if (new_max_size_kb > UINT32_MAX)
		return -EINVAL;
	if (new_max_size_kb > max_size_limit) {
		dev_err(&info->device->dev,
			"Requested buffer size exceeds maximum capacity\n");
		return -EINVAL;
	}
	new_max_size = (uint64_t)new_max_size_kb * bytes_per_kibi;
	if (new_max_size > UINT32_MAX)
		return -EINVAL;

	mutex_lock(&info->device->mutex);
	if (write_subdevice == NULL ||
	    (write_subdevice->subdev_flags & SDF_CMD_WRITE) == 0 ||
	    write_subdevice->async == NULL) {
		mutex_unlock(&info->device->mutex);
		return -EINVAL;
	}
	write_subdevice->async->max_bufsize = new_max_size;
	mutex_unlock(&info->device->mutex);

	return count;
}