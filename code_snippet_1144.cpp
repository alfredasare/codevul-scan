MagickExport FILE *GetImageInfoFile(const ImageInfo *image_info)
{
  return image_info->file ? image_info->file : NULL;
}