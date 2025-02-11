static void add_server_options(struct dhcp_packet *packet)
{
    struct option_set *curr = server_config.options;
    char buffer[packet->sname.size]; // Allocate a buffer with the correct size

    while (curr) {
        if (curr->data[OPT_CODE]!= DHCP_LEASE_TIME) {
            // Use memcpy instead of strncpy
            memcpy(buffer, curr->data, curr->size);
            udhcp_add_binary_option(packet, buffer);
        }
        curr = curr->next;
    }

    packet->siaddr_nip = server_config.siaddr_nip;

    if (server_config.sname) {
        // Use snprintf with explicit buffer size
        snprintf((char*)packet->sname, sizeof(packet->sname), "%s", server_config.sname);
    }
    if (server_config.boot_file) {
        // Use snprintf with explicit buffer size
        snprintf((char*)packet->file, sizeof(packet->file), "%s", server_config.boot_file);
    }
}