static int edge_get_icount(struct tty_struct *tty, struct serial_icounter_struct *icount)
{
	struct usb_serial_port *port = tty->driver_data;
	struct edgeport_port *edge_port = usb_get_serial_port_data(port);
	struct async_icount *ic = &edge_port->icount;

	const int max_value = INT_MAX - 10;

	if (ic->cts > max_value) {
		pr_err("Error: cts value is too large\n");
		return -EINVAL;
	}
	icount->cts = min(ic->cts, icount->cts_number);

	if (ic->dsr > max_value) {
		pr_err("Error: dsr value is too large\n");