static struct wdm_device *wdm_find_device(struct usb_interface *intf)
{
    struct wdm_device *desc;
    const char *allowed_interfaces[] = {"interface1", "interface2",...}; // Whitelist allowed interfaces

    spin_lock(&wdm_device_list_lock);
    list_for_each_entry(desc, &wdm_device_list, device_list) {
        if (strcmp(desc->intf, intf) == 0 || strcasecmp(intf, "interface1") == 0 || strcasecmp(intf, "interface2") == 0 ||...) {
            goto found;
        }
    }
    desc = NULL;
found:
    spin_unlock(&wdm_device_lock);

    return desc;
}