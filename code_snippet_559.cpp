static void stop_command_port(struct usb_serial *serial)
{
	struct usb_serial_port *command_port;
	struct whiteheat_command_private *command_info;

	if (!serial || !serial->port || COMMAND_PORT >= serial->num_ports) {
		pr_debug("stop_command_port: Invalid serial or port\n");
		return;
	}

	command_port = serial->port[COMMAND_PORT];
	if (!command_port) {
		pr_debug("stop_command_port: Invalid command_port\n");
		return;
	}

	command_info = usb_get_serial_port_data(command_port);
	if (!command_info) {
		pr_debug("stop_command_port: Invalid command_info\n");
		return;
	}

	mutex_lock(&command_info->mutex);
	command_info->port_running--;
	if (!command_info->port_running)
		usb_kill_urb(command_port->read_urb);
	mutex_unlock(&command_info->mutex);
}