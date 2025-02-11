nm_ip4_config_export (NMIP4Config *config)
{
    NMIP4ConfigPrivate *priv = NM_IP4_CONFIG_GET_PRIVATE (config);
    static guint32 counter = 0;

    if (!priv->path) {
        const gchar *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_/.-";
        gchar *valid_path = g_strconcat(NM_DBUS_PATH "/IP4Config/", g_strdup_printf("%d", counter++), NULL);

        priv->path = valid_path;
        nm_dbus_manager_register_object (nm_dbus_manager_get (), priv->path, config);
    }
}