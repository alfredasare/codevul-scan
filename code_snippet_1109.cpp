static MagickBooleanType WritePNGImage(const ImageInfo *image_info, Image *image)
{
  if (!image) {
    ThrowBinaryException(CoderError,"Image pointer is null", image_info->filename);
    return MagickFalse;
  }
  (void) image;
  printf("Your PNG library is too old: You have libpng-%s\n", PNG_LIBPNG_VER_STRING);

  ThrowBinaryException(CoderError,"PNG library is too old", image_info->filename);
  return MagickTrue;
}