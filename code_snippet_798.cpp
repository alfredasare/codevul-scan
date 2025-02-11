MagickExport void DisassociateBlob(Image *image)
{
 BlobInfo
 *magick\_restrict blob\_info,
 *clone\_info;

MagickBooleanType
clone;

assert(image != (Image *) NULL);
assert(image->signature == MagickCoreSignature);
if (image->debug != MagickFalse)
(void) LogMagickEvent(TraceEvent,GetMagickModule(),"%s",image->filename);

// Validate image->blob before using it
if (image->blob == (BlobInfo *) NULL || image->blob->signature != MagickCoreSignature || IsBlobDeleted(image->blob))
return;

blob\_info=image->blob;
clone=MagickFalse;
LockSemaphoreInfo(blob\_info->semaphore);
assert(blob\_info->reference\_count >= 0);
if (blob\_info->reference\_count > 1)
clone=MagickTrue;
UnlockSemaphoreInfo(blob\_info->semaphore);
if (clone == MagickFalse)
return;
clone\_info=CloneBlobInfo(blob\_info);
DestroyBlob(image);
image->blob=clone\_info;
}