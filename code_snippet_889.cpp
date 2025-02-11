MagickExport MagickBooleanType SyncImagesSettings(ImageInfo *image\_info,
Image \*images, ExceptionInfo \*exception)
{
Image
\*image;
const char \*page\_option = GetImageOption(image\_info, "page");
size\_t max\_page\_size = 1024; // Set a reasonable maximum size for the page option
char safe\_page[max\_page\_size];

assert(image\_info != (const ImageInfo \*) NULL);
assert(image\_info->signature == MagickCoreSignature);
assert(images != (Image \*) NULL);
assert(images->signature == MagickCoreSignature);
if (images->debug != MagickFalse)
(void) LogMagickEvent(TraceEvent,GetMagickModule(),"%s",images->filename);
if (page\_option && strlen(page\_option) < max\_page\_size) {
SafeCopyString(safe\_page, page\_option, max\_page\_size);
SetImageOption(image\_info, "page", safe\_page);
}
image=images;
for ( ; image != (Image \*) NULL; image=GetNextImageInList(image))
(void) SyncImageSettings(image\_info,image,exception);
(void) DeleteImageOption(image\_info,"page");
return(MagickTrue);
}

void SafeCopyString(char \*destination, const char \*source, size\_t size) {
if (destination && source) {
strncpy(destination, source, size - 1);
destination[size - 1] = ‘\0’;
}
}