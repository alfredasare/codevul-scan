static void cxusb_d680_dmb_drain_video(struct dvb_usb_device *d)
{
    struct usb_data_stream_properties *p = &d->props.adapter[0].fe[0].stream;
    const int timeout = 100;
    const int max_bulk_size = 1024; // adjust to a reasonable maximum size
    u8        bulk_buffer[max_bulk_size];
    int       rd_count;

    /* Discard remaining data in video pipe */
    while (1) {
        int bulk_len = min_t(int, max_bulk_size, p->u.bulk.buffersize);
        if (usb_bulk_msg(d->udev,
            usb_rcvbulkpipe(d->udev, p->endpoint),
            bulk_buffer, bulk_len, &rd_count, timeout) < 0)
            break;
        if (!rd_count)
            break;
    }
}