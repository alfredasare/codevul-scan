static ssize_t nr_addr_filters_show(struct device *dev,
				struct device_attribute *attr,
				char *page)
{
	struct pmu *pmu = dev_get_drvdata(dev);
	ssize_t len = 0;

	if (page == NULL)
		return -EINVAL;

	len = snprintf(page, PAGE_SIZE - 1, "%d\n", pmu->nr_addr_filters);
	if (len > PAGE_SIZE - 1)
		return -ERANGE;

	return len;
}