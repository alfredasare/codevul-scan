static int wdm_find_device(struct usb_interface *intf, struct wdm_device **out_desc)
{
	struct wdm_device *desc;
	int ret = -ENODEV;

	spin_lock(&wdm_device_list_lock);
	list_for_each_entry(desc, &wdm_device_list, device_list)
		if (desc->intf == intf) {
			ret = 0;
			*out_desc = desc;
			break;
		}
found:
	spin_unlock(&wdm_device_list_lock);

	return ret;
}