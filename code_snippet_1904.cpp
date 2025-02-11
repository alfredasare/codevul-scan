static ssize_t release_date_show(struct device_driver *dd, char *buf)
{
    if (buf == NULL) {
        return -EINVAL;
    }
    return snprintf(buf, strlen(MEGASAS_RELDATE) + 2, "%s\n", MEGASAS_RELDATE);
}