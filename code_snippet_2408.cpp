guint8 buffer[16]; // fixed-size buffer
guint64 length;
guint32 fourcc;

length = g_ntohl(*(guint32 *)data);
GST_DEBUG("length %08" G_GINT64_MODIFIER "x", length);
fourcc = g_ntohl(*(guint32 *)(data + 4));
GST_DEBUG("atom type %" GST_FOURCC_FORMAT, GST_FOURCC_ARGS(fourcc));

if (plength)
    *plength = length;
if (pfourcc)
    *pfourcc = fourcc;