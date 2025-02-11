static ssize_t regulator_suspend_mem_mode_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct regulator_dev *rdev = dev_get_drvdata(dev);
	ssize_t ret;

	ret = regulator_print_opmode(buf, rdev->constraints->state_mem.mode);
	if (ret < 0) {
		return ret;
	}

	return ret;
}