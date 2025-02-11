#include <linux/mutex.h>

static DEFINE_MUTEX(usb_mem_mutex);

static void usbfs_decrease_memory_usage(unsigned amount)
{
	mutex_lock(&usb_mem_mutex);
	atomic_sub(amount, &usbfs_memory_usage);
	mutex_unlock(&usb_mem_mutex);
}