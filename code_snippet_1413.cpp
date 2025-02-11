struct usb_interface *usbhid_find_interface(int minor)
{
    if (minor < 0 || minor >= USB_MINORS) {
        return NULL;
    }
    return usb_find_interface(&hid_driver, minor);
}