static int csnmp_config_add_host_version(host_definition_t *hd, oconfig_item_t *ci) {
  int version;

  if (ci->values_num!= 1) {
    WARNING("snmp plugin: The `Version' config option needs exactly one argument.");
    return (-1);
  }

  oconfig_value_t *value = &ci->values[0];
  if (value->type!= OCONFIG_TYPE_NUMBER) {
    WARNING("snmp plugin: The `Version' config option value must be a number.");
    return (-1);
  }

  version = (int)value->number;
  switch (version) {
    case 1:
    case 2:
    case 3:
      hd->version = version;
      break;
    default:
      WARNING("snmp plugin: `Version' must be either `1', `2', or `3'.");
      return (-1);
  }

  return (0);
} /* int csnmp_config_add_host_address */