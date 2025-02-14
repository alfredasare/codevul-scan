static ssize_t disk_ro_show(struct device *dev,
			   struct device_attribute *attr, char *buf)
{
	struct gendisk *disk = dev_to_disk(dev);

	return snprintf(buf, sizeof(buf), "%d\n", get_disk_ro(disk) ? 1 : 0);
}