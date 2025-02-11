vmnc_handle_wmvg_rectangle (GstVMncDec * dec, struct RfbRectangle *rect,
    const guint8 * data, int len, gboolean decode)
{
  if (len < 10) {
    return ERROR_INSUFFICIENT_DATA;
  }
  return 10;
}