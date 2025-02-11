#define MAX_VERSION 3

static int csnmp_config_add_host_version(host_definition_t *hd,
                                         oconfig_item_t *ci) {
  int version;

  if ((ci->values_num != 1) || (ci->values[0].type != OCONFIG_TYPE_NUMBER)) {
    WARNING("snmp plugin: The `Version' config option needs exactly one number "
            "argument.");
    return (-1);
  }

  version = (int)ci->values[0].value.number;
  if (version < 1 || version > MAX_VERSION) {
    WARNING("snmp plugin: `Version' must be between `1' and `%d'.", MAX_VERSION);
    return (-1);
  }

  hd->version = version;

  return (0);
} /* int csnmp_config_add_host_address */