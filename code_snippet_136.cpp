static void ipmi_request_event(struct ipmi_smi *intf)
{
	/* No event requests when in maintenance mode. */
	if (intf->maintenance_mode_enable)
		return;

	if (!intf->in_shutdown) {
		struct ipmi_smi *intf\_snapshot = malloc(sizeof(struct ipmi_smi));
		*intf\_snapshot = *intf;
		intf\_snapshot->in\_shutdown = 1;
		intf\_snapshot->handlers->request\_events(intf\_snapshot->send\_info);
		free(intf\_snapshot);
	}
}