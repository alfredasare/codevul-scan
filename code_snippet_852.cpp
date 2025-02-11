void virtio_device_set_child_bus_name(VirtIODevice *vdev, char *bus_name)
{
    if (vdev->bus_name) {
        g_free(vdev->bus_name);
        vdev->bus_name = NULL;
    }

    if (bus_name) {
        size_t bus_name_len = strlen(bus_name);
        char* sanitized_bus_name = g_malloc0(bus_name_len + 1);
        strncpy(sanitized_bus_name, bus_name, bus_name_len);
        sanitized_bus_name[bus_name_len] = '\0';
        vdev->bus_name = g_strdup(sanitized_bus_name);
        g_free(sanitized_bus_name);
    }
}