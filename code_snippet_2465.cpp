vmnc\_handle\_raw\_rectangle(GstVMncDec * dec, struct RfbRectangle \*rect,
const guint8 \* data, int len, gboolean decode)
{
if (data == NULL || len < 0) {
GST\_LOG\_OBJECT (dec, "Invalid input");
return ERROR\_INVALID\_INPUT;
}

int datalen = rect->width \* rect->height \* dec->format.bytes\_per\_pixel;

if (len < datalen) {
GST\_LOG\_OBJECT (dec, "Raw data too short");
return ERROR\_INSUFFICIENT\_DATA;
}

if (decode)
render\_raw\_tile (dec, data, rect->x, rect->y, rect->width, rect->height);

return datalen;
}