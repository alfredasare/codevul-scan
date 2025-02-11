code:


int add_unix_port(smartlist_t **ports, rend_service_port_config_t *p)
{
    if (!ports ||!p) {
        return -EINVAL; 
    }

    smartlist_t *new_ports = smartlist_new();
    if (!new_ports) {
        return -ENOMEM; 
    }

    smartlist_add(*ports, new_ports);

    return 0; 
}