extract_initial_length_and_fourcc (guint8 *data, guint64 *plength, guint32 *pfourcc, guint64 buffer_size)
{
  guint64 length;
  guint32 fourcc;

  length = QT_UINT32 (data);
  GST_DEBUG ("length %08" G_GINT64_MODIFIER "x", length);
  fourcc = QT_FOURCC (data + 4);
  GST_DEBUG ("atom type %" GST_FOURCC_FORMAT, GST_FOURCC_ARGS (fourcc));

  if (length == 0) {
    length = G_MAXUINT32;
  } else if (length == 1) {
    /* this means we have an extended size, which is the 64 bit value of
     * the next 8 bytes */
    if (buffer_size < 12) { // Check if the remaining buffer is large enough
      g_printerr("Error: Insufficient buffer size\n");
      return;
    }
    length = QT_UINT64 (data + 8);
    GST_DEBUG ("length %08llx", length);
  }

  // Adjust the length to fit the buffer size
  if (length > buffer_size - 4) {
    length = buffer_size - 4;
  }

  if (plength)
    *plength = length;
  if (pfourcc)
    *pfourcc = fourcc;
}