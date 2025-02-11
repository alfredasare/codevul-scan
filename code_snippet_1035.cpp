g_NP_GetMIMEDescription(void)
{
  if (g_plugin_NP_GetMIMEDescription == NULL)
	return NULL;

  D(bugiI("NP_GetMIMEDescription\n"));

  char *str = g_plugin_NP_GetMIMEDescription();
  if (str!= NULL && str[0]!= '\0') {
    D(bugiD("NP_GetMIMEDescription return: %s\n", str));
  } else {
    D(bugiD("NP_GetMIMEDescription return: <empty>\n"));
  }
  return str;
}