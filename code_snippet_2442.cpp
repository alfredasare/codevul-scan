vmnc_handle_wmvg_rectangle (GstVMncDec * dec, struct RfbRectangle *rect,
                            const guint8 * data, int len, gboolean decode)
{
  const int MINIMUM_DATA_LENGTH = 10; // Add this line with the actual minimum length required

  /* Check if the data length is sufficient for further processing */
  if (len < MINIMUM_DATA_LENGTH) {
    GST_LOG_OBJECT (dec, "Data is too short, expected at least %d bytes", MINIMUM_DATA_LENGTH);
    return ERROR_INSUFFICIENT_DATA;
  }

  /* Keyboard stuff; not interesting for playback */

  return 10;
}