static ssize_t lbs_bcnmiss_write(struct file *file, const char __user *userbuf,
				 size_t count, loff_t *ppos)
{
    size_t bufsize = get_size_of_buffer(); // Replace with actual buffer size
    if (count > bufsize) {
        return -EINVAL; // Return an error if the count exceeds the buffer size
    }

    return lbs_threshold_write(TLV_TYPE_BCNMISS, CMD_SUBSCRIBE_BCNMISS,
			       file, userbuf, count, ppos);
}