static long snd_timer_user_ioctl(struct file *file, unsigned int cmd,
                                 unsigned long arg)
{
	struct snd_timer_user *tu = file->private_data;
	long ret;

	if (!tu || IS_ERR(tu)) {
		printk(KERN_ERR "snd_timer_user_ioctl: invalid private_data\n");
		return -EINVAL;
	}

	mutex_lock(&tu->ioctl_lock);
	ret = __snd_timer_user_ioctl(file, cmd, arg);
	mutex_unlock(&tu->ioctl_lock);
	return ret;
}