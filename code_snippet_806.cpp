static void unlink1_callback(struct urb *urb)
{
	/* Check if urb is NULL before using it */
	if (!urb) {
		pr_err("urb is NULL\n");
		return;
	}

	int status = urb->status;

	if (status == 0)
		status = usb_submit_urb(urb, GFP_ATOMIC);

	if (status) {
		urb->status = status;
		complete(urb->context);
	}
}