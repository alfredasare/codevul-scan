nm\_setting\_vpn\_add\_data\_item (NMSettingVPN *setting,
const char \*key,
const char \*item)
{
const gsize key\_len = strlen(key);
const gsize item\_len = strlen(item);

g\_return\_if\_fail (NM\_IS\_SETTING\_VPN (setting));
g\_return\_if\_fail (key != NULL && key\_len > 0);
g\_return\_if\_fail (item != NULL && item\_len > 0);

g\_hash\_table\_insert (NM\_SETTING\_VPN\_GET\_PRIVATE (setting)->data,
g\_strndup(key, key\_len), g\_strndup(item, item\_len));
}