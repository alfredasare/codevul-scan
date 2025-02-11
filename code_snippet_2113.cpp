#include <linux/mutex.h>

static DEFINE_MUTEX(usbcons_mutex);

void usb_serial_console_disconnect(struct usb_serial *serial)
{
	if (serial->port[0] == usbcons_info.port) {
		mutex_lock(&usbcons_mutex);
		if (serial->port[0] == usbcons_info.port) {
			usb_serial_console_exit();
			usb_serial_put(serial);
		}
		mutex_unlock(&usbcons_mutex);
	}
}