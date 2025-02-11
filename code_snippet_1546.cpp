static unsigned char *AcquireCompactPixels(const Image *image, ExceptionInfo *exception)
{
  size_t packet_size, row_stride;
  unsigned char *compact_pixels;

  packet_size = (image->depth > 8UL) ? 2UL : 1UL;
  row_stride = image->columns * packet_size;

  compact_pixels = calloc(1, row_stride * image->rows * sizeof(*compact_pixels));

  if (compact_pixels == NULL)
  {
    (void) ThrowMagickException(exception, GetMagickModule(),
      ResourceLimitError, "MemoryAllocationFailed", "`%s'",
      image->filename);
  }

  return(compact_pixels);
}