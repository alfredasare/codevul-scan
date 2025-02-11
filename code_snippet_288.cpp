int compat_get_timespec64(struct timespec64 __user *ts, const void __user *uts)
{
	if (COMPAT_USE_64BIT_TIME) {
		struct timespec64 kts;
		if (copy_from_user(&kts, uts, sizeof(kts)))
			return -EFAULT;
		*ts = kts;
		return 0;
	} else {
		return __compat_get_timespec64(ts, uts);
	}
}