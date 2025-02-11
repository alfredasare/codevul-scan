static int edge_get_icount(struct tty_struct *tty, struct serial_icounter_struct *icount)
{
    struct usb_serial_port *port = tty->driver_data;
    struct edgeport_port *edge_port = usb_get_serial_port_data(port);
    struct async_icounter *ic = &edge_port->icount;

    if (ic->cts < 0 || ic->dsr < 0 || ic->rng < 0 || ic->dcd < 0 || ic->tx < 0 || ic->rx < 0 || ic->frame < 0 || ic->parity < 0 || ic->overrun < 0 || ic->brk < 0 || ic->buf_overrun < 0) {
        // Handle invalid values or sanitize them
        //...
    }

    if (secure_storage_enabled()) {
        // Encrypt or hash the icount values
        //...
    }

    if (!has_access_permission(tty)) {
        // Return an error or omit the sensitive information
        //...
    }

    icount->cts = ic->cts;
    icount->dsr = ic->dsr;
    icount->rng = ic->rng;
    icount->dcd = ic->dcd;
    icount->tx = ic->tx;
    icount->rx = ic->rx;
    icount->frame = ic->frame;
    icount->parity = ic->parity;
    icount->overrun = ic->overrun;
    icount->brk = ic->brk;
    icount->buf_overrun = ic->buf_overrun;
    return 0;
}