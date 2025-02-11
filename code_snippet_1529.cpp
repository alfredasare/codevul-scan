read_report_descriptor(struct file *filp, struct kobject *kobj,
		      struct bin_attribute *attr,
		      char *buf, loff_t off, size_t count)
{
    struct device *dev = kobj_to_dev(kobj);
    struct hid_device *hdev = to_hid_device(dev);

    if (off >= hdev->rsize) {
        return 0;
    }

    size_t max_count = hdev->rsize - off;
    if (count > max_count) {
        count = max_count;
    }

    memcpy(buf, hdev->rdesc + off, count);

    return count;
}