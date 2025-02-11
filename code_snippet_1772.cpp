void xen_pcibk_config_free_dev(struct pci_dev *dev)
{
    struct xen_pcibk_dev_data *dev_data;
    struct config_field_entry *cfg_entry, *t;
    const struct config_field *field;

    dev_dbg(&dev->dev, "free-ing virtual configuration space fields\n");

    if (!dev ||!dev->driver ||!dev->driver->driver_data)
        return; // Ensure dev is valid

    dev_data = pci_get_drvdata(dev);
    if (!dev_data)
        return; // Ensure dev_data is not null

    list_for_each_entry_safe(cfg_entry, t, &dev_data->config_fields, list) {
        if (!cfg_entry ||!t)
            continue; // Ensure cfg_entry and t are valid

        list_del(&cfg_entry->list);

        field = cfg_entry->field;

        if (field && field->release)
            field->release(dev, OFFSET(cfg_entry), cfg_entry->data);

        kfree(cfg_entry);
    }
}