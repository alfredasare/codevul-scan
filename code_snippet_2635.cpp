#include <linux/uaccess.h>

static ssize_t lbs_bcnmiss_write(struct file *file, const char __user *userbuf,
				size_t count, loff_t *ppos)
{
	char userbuf_copy[256]; // Allocate a reasonable buffer size for the copy
	ssize_t retval;

	if (count > sizeof(userbuf_copy)) {
		pr_warn("Truncating oversized user input\n");
		count = sizeof(userbuf_copy);
	}

	if (copy_from_user(userbuf_copy, userbuf, count)) {
		return -EFAULT;
	}

	retval = lbs_threshold_write(TLV_TYPE_BCNMISS, CMD_SUBSCRIBE_BCNMISS,
				     file, userbuf_copy, count, ppos);

	return retval;
}