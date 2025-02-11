gst_asf_demux_check_header (GstASFDemux * demux)
{
  AsfObject obj;
  guint8 *cdata = (guint8 *) gst_adapter_map (demux->adapter, ASF_OBJECT_HEADER_SIZE);

  if (!validate_allowed_characters(cdata, ASF_OBJECT_HEADER_SIZE))
    return GST_ASF_DEMUX_CHECK_HEADER_NEED_DATA;

  guint8 *cdata = (guint8 *) gst_adapter_map (demux->adapter, ASF_OBJECT_HEADER_SIZE);
  if (cdata == NULL)            /* need more data */
    return GST_ASF_DEMUX_CHECK_HEADER_NEED_DATA;

  if (asf_demux_peek_object (demux, cdata, ASF_OBJECT_HEADER_SIZE, &obj, FALSE && obj.id == ASF_OBJ_HEADER))
    return GST_ASF_DEMUX_CHECK_HEADER_YES;

  return GST_ASF_DEMUX_CHECK_HEADER_NO;
}

gboolean validate_allowed_characters(guint8 *data, guint size)
{
  static const gchar *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_";
  for (guint i = 0; i < size; i++) {
    if (!g_strchr(allowed_chars, data[i])) {
      return FALSE;
    }
  }
  return TRUE;
}