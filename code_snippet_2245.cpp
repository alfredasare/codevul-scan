vmnc_handle_raw_rectangle (GstVMncDec * dec, struct RfbRectangle *rect,
const guint8 * data, int len, gboolean decode)
{
  int datalen = rect->width * rect->height * dec->format.bytes_per_pixel;

  if (len < datalen) {
    GST_LOG_OBJECT (dec, "Raw data too short");
    return ERROR_INSUFFICIENT_DATA;
  }

  if (dec->format.bytes_per_pixel != 1 && dec->format.bytes_per_pixel != 2 && dec->format.bytes_per_pixel != 3 && dec->format.bytes_per_pixel != 4) {
    GST_LOG_OBJECT (dec, "Invalid data format");
    return ERROR_INVALID_DATA_FORMAT;
  }

  if (decode)
    render_raw_tile (dec, data, rect->x, rect->y, rect->width, rect->height);

  return datalen;
}