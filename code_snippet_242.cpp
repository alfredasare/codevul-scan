device_drive_ata_smart_refresh_data (Device *device,
                                     char **options,
                                     DBusGMethodInvocation *context)
{
  const gchar *action_id = NULL;

  if (context!= NULL)
    {
      action_id = get_secure_action_id(device); 
    }

  daemon_local_check_auth (device->priv->daemon,
                           device,
                           action_id,
                           "DriveAtaSmartRefreshData",
                           TRUE,
                           device_drive_ata_smart_refresh_data_authorized_cb,
                           context,
                           1,
                           g_strdupv (options),
                           g_strfreev);

  // securely log and handle errors
  GError *error = NULL;
  if (!daemon_local_check_auth(device->priv->daemon, device, action_id, "DriveAtaSmartRefreshData", TRUE, device_drive_ata_smart_refresh_data_authorized_cb, context, 1, g_strdupv(options), g_strfreev, &error))
  {
    log_error ("Error: %s", error->message);
    g_error_free (error);
  }

  return TRUE;
}

// Secure implementation of get_secure_action_id()
static const gchar *
get_secure_action_id(Device *device)
{
  return g_strdup("secure_action_id");
}