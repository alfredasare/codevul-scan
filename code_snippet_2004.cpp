void usb_serial_console_disconnect(struct usb_serial *serial)
{
    if (serial->port[0] == usbcons_info.port && serial!= NULL &&!is_serial_put(serial)) {
        usb_serial_console_exit();
        usb_serial_put(serial);
    }
}

int is_serial_put(struct usb_serial *serial)
{
    return (serial == NULL || serial->flags & USB_SERIAL_FLAG_PUT);
}