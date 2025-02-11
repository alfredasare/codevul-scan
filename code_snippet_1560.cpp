struct usb\_interface *usbhid\_find\_interface(int minor)
{
 struct usb\_interface *interface = usb\_find\_interface(&hid\_driver, minor);
 if (!interface) {
 /* Handle error case */
 return NULL;
 }

 return interface;
}