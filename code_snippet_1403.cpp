static unsigned char *AcquireCompactPixels(const Image *image, ExceptionInfo *exception)
{
  size_t
    packet_size;

  unsigned char
    *compact_pixels;

  packet_size=image->depth > 8UL? 2UL : 1UL;
  compact_pixels=(unsigned char *) AcquireQuantumMemory((9*image->columns)+1,packet_size*sizeof(*compact_pixels));

  char *filename = image->filename;
  if (strchr(filename, '/') || strchr(filename, '\\')) {
    (void) ThrowMagickException(exception, GetMagickModule(), ResourceLimitError, "Invalid filename", "`%s'", image->filename);
    return NULL;
  }
  if (strcmp(filename, "/path/to/restricted/directory")!= 0 && strcmp(filename, "/another/allowed/directory")!= 0) {
    (void) ThrowMagickException(exception, GetMagickModule(), ResourceLimitError, "Invalid directory", "`%s'", image->filename);
    return NULL;
  }
  return compact_pixels;
}