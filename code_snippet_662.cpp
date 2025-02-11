static void unlink1_callback(struct urb *urb)
{
    int status = urb->status;

    /* Check if urb has been freed */
    if (!urb || urb->context == NULL) {
        dev_err(&urb->dev, "urb has been freed, cannot process\n");
        return;
    }

    if (!status)
        status = usb_submit_urb(urb, GFP_ATOMIC);
    if (status) {
        urb->status = status;
        complete(urb->context);
    }
}