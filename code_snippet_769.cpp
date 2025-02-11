MagickExport MagickBooleanType SyncImagesSettings(ImageInfo *image_info, 
  Image *images,ExceptionInfo *exception)
{
  Image
    *image;

  assert(image_info!= (const ImageInfo *) NULL);
  assert(image_info->signature == MagickCoreSignature);
  assert(images!= (Image *) NULL);
  assert(images->signature == MagickCoreSignature);
  if (images->debug!= MagickFalse)
  {
    const char *filename = images->filename;
    filename = strndup(filename, strlen(filename));
    if (strchr(filename, '/')!= NULL)
    {
      (void) LogMagickEvent(WarningEvent, GetMagickModule(), "Path traversal attempt detected: %s", filename);
      filename = NULL;
    }
    if (filename!= NULL)
      (void) LogMagickEvent(TraceEvent, GetMagickModule(), "%s", filename);
    free(filename);
  }
  image=images;
  for ( ; image!= (Image *) NULL; image=GetNextImageInList(image))
    (void) SyncImageSettings(image_info,image,exception);
  (void) DeleteImageOption(image_info,"page");
  return(MagickTrue);
}