static MagickBooleanType WritePNGImage(const ImageInfo *image_info, Image *image)
{
  (void) image;
  ThrowBinaryException(CoderError,"PNG library is too old", image_info->filename);
}