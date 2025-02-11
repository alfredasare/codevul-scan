acpi_map_lookup(acpi_physical_address phys, acpi_size size)
{
	struct acpi_ioremap *map;
	mutex_lock(&acpi_ioremap_mutex);
	list_for_each_entry_rcu(map, &acpi_ioremaps, list)
		if (map->phys <= phys &&