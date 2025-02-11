int usb_lock_device_for_reset(struct usb_device *udev,
			      const struct usb_interface *iface)
{
	unsigned long jiffies_expire = jiffies + HZ; // 1 second timeout
	int attempts = 0;
	struct mutex *mutex;

	mutex = &udev->reset_mutex; // introduce a mutex for locking
	mutex_lock(&mutex);

	if (udev->state == USB_STATE_NOTATTACHED)
		return -ENODEV;
	if (udev->state == USB_STATE_SUSPENDED)
		return -EHOSTUNREACH;
	if (iface && (iface->condition == USB_INTERFACE_UNBINDING ||
			iface->condition == USB_INTERFACE_UNBOUND))
		return -EINTR;

	while (!mutex_lock_interruptible(mutex)) {
		attempts++;

		/* If we can't acquire the lock after waiting one second, or
		 * after a maximum of 10 attempts, we're probably deadlocked */
		if (time_after(jiffies, jiffies_expire) || attempts > 10) {
			mutex_unlock(&mutex);
			return -EBUSY;
		}

		msleep(15);
		if (udev->state == USB_STATE_NOTATTACHED)
			return -ENODEV;
		if (udev->state == USB_STATE_SUSPENDED)
			return -EHOSTUNREACH;
		if (iface && (iface->condition == USB_INTERFACE_UNBINDING ||
				iface->condition == USB_INTERFACE_UNBOUND))
			return -EINTR;
	}

	mutex_unlock(&mutex);
	return 0;
}