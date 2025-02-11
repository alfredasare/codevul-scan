_dbus_header_get_field_raw (DBusHeader        *header,
                        int                field,
                        const DBusString **str,
                        int               *pos)
{
  if (field < 0 || field >= header->num_fields)
    return FALSE;

  if (!_dbus_header_cache_check (header, field))
    return FALSE;

  if (str)
    *str = &header->data;
  if (pos)
    *pos = header->fields[field].value_pos;

  return TRUE;
}