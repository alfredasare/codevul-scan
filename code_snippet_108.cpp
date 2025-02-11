static int network_config_set_interface (const oconfig_item_t *ci, /* {{{ */
                                          int *interface)
{
  if (ci && ci->values_num > 0 && ci->values &&
      ci->values_num <= CONFIG_MAX_VALUES &&
      ci->values[0].type == OCONFIG_TYPE_STRING)
  {
    if (interface == NULL)
      return (-1);

    *interface = if_nametoindex (ci->values[0].value.string);

    return (0);
  }

  WARNING ("network plugin: The `Interface' config option needs exactly "
           "one string argument.");
  return (-1);
} /* }}} int network_config_set_interface */