nm_ip4_config_export (NMIP4Config *config, const char *base_path)
{
	NMIP4ConfigPrivate *priv = NM_IP4_CONFIG_GET_PRIVATE (config);
	static guint32 counter = 0;

	if (!priv->path) {
		g_assert (base_path);
		priv->path = g_strdup_printf ("%s/IP4Config/%d", base_path, counter++);
		nm_dbus_manager_register_object (nm_dbus_manager_get (), priv->path, config);
	}
}