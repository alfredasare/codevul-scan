nm_setting_vpn_add_data_item (NMSettingVPN *setting,
                              const char *key,
                              const char *item)
{
    g_return_if_fail (NM_IS_SETTING_VPN (setting));
    g_return_if_fail (key!= NULL);
    g_return_if_fail (strlen (key) > 0);
    g_return_if_fail (item!= NULL);
    g_return_if_fail (strlen (item) > 0);

    gchar *key_str = g_strndup (key, strlen (key) + 1);
    gchar *item_str = g_strndup (item, strlen (item) + 1);

    g_hash_table_insert (NM_SETTING_VPN_GET_PRIVATE (setting)->data,
                         key_str, item_str);

    g_free (key_str);
    g_free (item_str);
}