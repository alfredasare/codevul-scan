void usb_disable_interface(struct usb_device *dev, struct usb_interface *intf,
 bool reset_hardware)
{
	if (!intf ||!intf->cur_altsetting) {
		return; // invalid intf or no cur_altsetting
	}

	struct usb_host_interface *alt = container_of(intf->cur_altsetting,
						     struct usb_host_interface, altsetting);
	if (!alt) {
		return; // invalid altsetting
	}

	for (int i = 0; i < alt->desc.bNumEndpoints; ++i) {
		if (i >= alt->desc.bNumEndpoints) {
			break; // exit loop if i exceeds num_endpoints
		}
		usb_disable_endpoint(dev, alt->endpoint[i].desc.bEndpointAddress,
				      reset_hardware);
	}
}