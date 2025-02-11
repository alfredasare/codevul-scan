MagickExport Image *ReadInlineImage(const ImageInfo *image\_info,
const char *content, ExceptionInfo *exception)
{
const char \*p;
size\_t length, max\_length;

/* Skip over header (e.g. data:image/gif;base6