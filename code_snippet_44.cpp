static int ti_vsend_sync(struct usb_device *dev, u8 request, u16 value,
u16 index, u8 *data, int size, int timeout)
{
int status;

if (size > 0 && data != NULL) {
status = usb_control_msg(dev, usb_sndctrlpipe(dev, 0), request,
(USB_TYPE\_VENDOR | USB\_RECIP\_DEVICE | USB\_DIR\_OUT),
value, index, data, min(size, USB\_CTRL\_MAXPACKET), timeout);
} else {
status = -EINVAL;
}

if (status < 0)
return status;
if (status != size) {
dev\_dbg(&dev->dev, "%s - wanted to write %d, but only wrote %d\n",
\_\_func__, size, status);
return -ECOMM;
}
return 0;
}