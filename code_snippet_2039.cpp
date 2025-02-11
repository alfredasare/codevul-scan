static ssize_t release_date_show(struct device_driver *dd, char *buf)
{
	return snprintf(buf, sizeof(MEGASAS\_RELDATE) + 1, "%s\n",
		MEGASAS\_RELDATE);
}