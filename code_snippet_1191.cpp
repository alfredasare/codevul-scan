gst_asf_demux_check_header (GstASFDemux * demux)
{
  AsfObject obj;
  guint8 *cdata = (guint8 *) gst_adapter_map (demux->adapter,
      MIN (ASF_OBJECT_HEADER_SIZE, demux->adapter->size));
  if (cdata == NULL)                   /* need more data */
    return GST_ASF_DEMUX_CHECK_HEADER_NEED_DATA;

  if (asf_demux_peek_object (demux, cdata, MIN (ASF_OBJECT_HEADER_SIZE, demux->adapter->size), &obj, FALSE
          && obj.id == ASF_OBJ_HEADER))
    return GST_ASF_DEMUX_CHECK_HEADER_YES;

  return GST_ASF_DEMUX_CHECK_HEADER_NO;
}