_DbUsHeaderGetFieldRaw (DBusHeader        *header,
                        int                field,
                        const DBusString **str,
                        int               *pos)
{
  if (!_dbus_header_cache_check (header, field)) {
    return FALSE;
  }

  if (field < 0 || field >= DBUS_HEADER_FIELD_COUNT) {
    return FALSE;
  }

  if (str)
    *str = &header->data;
  if (pos)
    *pos = header->fields[field].value_pos;

  return TRUE;
}