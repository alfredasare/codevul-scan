static void usbip_pack_ret_submit(struct usbip_header *pdu, struct urb *urb, int pack)
{
    struct usbip_header_ret_submit *rpdu = &pdu->u.ret_submit;

    if (pack >= 0 && pack <= 1) {
        if (pack) {
            rpdu->status	= urb->status;
            rpdu->actual_length	= urb->actual_length;
            rpdu->start_frame	= urb->start_frame;
            rpdu->number_of_packets = urb->number_of_packets;
            rpdu->error_count	= urb->error_count;
        } else {
            rpdu->status	= 0;
            rpdu->actual_length	= 0;
            rpdu->start_frame	= 0;
            rpdu->number_of_packets = 0;
            rpdu->error_count	= 0;
            urb->status	= rpdu->status;
            urb->actual_length	= rpdu->actual_length;
            urb->start_frame	= rpdu->start_frame;
            urb->number_of_packets = rpdu->number_of_packets;
            urb->error_count	= rpdu->error_count;
        }
    } else {
        // Handle invalid pack value
    }
}