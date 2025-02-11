static ssize_t k90_show_current_profile(struct device *dev,
					struct device_attribute *attr,
					char *buf)
{
	int ret;
	struct usb_interface *usbif = to_usb_interface(dev->parent);
	struct usb_device *usbdev = interface_to_usbdev(usbif);
	int current_profile;
	char data[8];

	ret = usb_control_msg(usbdev, usb_rcvctrlpipe(usbdev, 0),
			      K90_REQUEST_STATUS,