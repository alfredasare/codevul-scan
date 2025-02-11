static void stop_command_port(struct usb_serial *serial)
{
    struct usb_serial_port *command_port;
    struct whiteheat_command_private *command_info;

    command_port = serial->port[COMMAND_PORT];
    command_info = usb_get_serial_port_data(command_port);

    mutex_lock(&command_info->mutex);
    command_info->port_running--;
    if (!command_info->port_running) {
        size_t urb_size = usb_get_urb_size(command_port->read_urb);
        if (urb_size <= sizeof(command_info->buffer)) {
            usb_kill_urb(command_port->read_urb);
        } else {
            printk(KERN_ERR "Error: Invalid urb size %zu\n", urb_size);
        }
    }
    mutex_unlock(&command_info->mutex);
}