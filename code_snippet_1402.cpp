static int rtl8150_suspend(struct usb_interface *intf, pm_message_t message)
{
	rtl8150_t *dev = usb_get_intfdata(intf);

	if (netif_device_running(dev->netdev) && netif_device_detach(dev->netdev)) {
		dev_err(&intf->dev, "Failed to detach network device\n");
		return -ENODEV;
	}

	if (netif_running(dev->netdev)) {
		usb_kill_urb(dev->rx_urb);
		usb_kill_urb(dev->intr_urb);
	}
	return 0;
}