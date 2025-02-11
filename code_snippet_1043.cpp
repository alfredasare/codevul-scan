MagickExport void AcquireNextImage(const ImageInfo \*image\_info, Image \*image,
ExceptionInfo \*exception)
{
 assert(image != (Image \*) NULL);
 assert(image->signature == MagickCoreSignature);
 if (image->debug != MagickFalse)
 (void) LogMagickEvent(TraceEvent,GetMagickModule(),"%s",image->filename);
 image->next=AcquireImage(image\_info,exception);
 if (GetNextImageInList(image) == (Image \*) NULL)
 return;
 size\_t filename\_length = strlen(image\_info->filename);
 if (filename\_length >= MagickPathExtent)
 {
 // Handle error case, e.g. by logging an error message and returning early
 }
 else
 {
 strncpy(GetNextImageInList(image)->filename, image\_info->filename,
 filename\_length + 1);
 }
 DestroyBlob(GetNextImageInList(image));
 image->next->blob=ReferenceBlob(image->blob);
 image->next->endian=image->endian;
 image->next->scene=image->scene+1;
 image->next->previous=image;
}