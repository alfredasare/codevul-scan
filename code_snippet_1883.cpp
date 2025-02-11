void usb_disable_interface(struct usb_device *dev, struct usb_interface *intf,
		bool reset_hardware)
{
	struct usb_host_interface *alt = intf->cur_altsetting;
	int i;

	for (i = 0; i < alt->desc.bNumEndpoints; ++i) {
		int retval = usb_disable_endpoint(dev,
				alt->endpoint[i].desc.bEndpointAddress,
				reset_hardware);
		if (retval < 0) {
			dev_err(&intf->dev, "Failed to disable endpoint %d\n",
				alt->endpoint[i].desc.bEndpointAddress);
			// Handle the error here, e.g., retry, log, or propagate the error
		}
	}
}