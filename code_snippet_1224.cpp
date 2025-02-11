advertise_sasl_exit(hook_data_client_exit *data)
{
    if (!ConfigFileEntry.sasl_service)
        return;

    static const char* allowed_sasl_services[] = {"service1", "service2", "service3"};
    int num_allowed_services = sizeof(allowed_sasl_services) / sizeof(allowed_sasl_services[0]);

    int i;
    for (i = 0; i < num_allowed_services; i++) {
        if (irccmp(data->target->name, allowed_sasl_services[i])) {
            sendto_local_clients_with_capability(CLICAP_CAP_NOTIFY, ":%s CAP * DEL :sasl", me.name);
            return;
        }
    }

    // If the service name is not in the whitelist, do not send the CAP command
    return;
}