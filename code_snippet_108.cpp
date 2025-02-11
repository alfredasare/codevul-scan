static int network_config_set_interface (const oconfig_item_t *ci, int *interface)
{
  const char *input_string = ci->values[0].value.string;

  if (strchr(input_string, '/') || strchr(input_string, '\\')) {
    WARNING ("network plugin: Invalid interface name detected. Aborting.");
    return (-1);
  }

  char *sanitized_string = strdup(input_string);
  char *token = strtok_r(sanitized_string, "/\\", &sanitized_string);

  if (token == NULL) {
    WARNING ("network plugin: Invalid interface name detected. Aborting.");
    free(sanitized_string);
    return (-1);
  }

  if (strlen(token) > IFNAMSIZ) {
    WARNING ("network plugin: Interface name too long. Aborting.");
    free(sanitized_string);
    return (-1);
  }

  *interface = if_nametoindex(token);

  free(sanitized_string);
  return (0);
}