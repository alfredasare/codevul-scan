strncpy(info.internal_name, info.external_name, info.length);
	info.internal_name[info.length] = '\0';
	return_ACPI_STATUS(status);
}