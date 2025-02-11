static ssize_t nr_addr_filters_show(struct device *dev,
				   struct device_attribute *attr,
				   char *page)
{
    struct pmu *pmu = dev_get_drvdata(dev);
    const size_t max_len = 256;

    return snprintf(page, max_len, "%d\n", pmu->nr_addr_filters);
}