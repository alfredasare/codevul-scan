MagickExport ssize\_t WriteBlobString(Image \*image, const char \*string)
{
 assert(image != (Image \*) NULL);
 assert(image->signature == MagickCoreSignature);

 if(string == NULL || image == NULL) return(-1);

 size\_t stringLength = strlen(string);
 if(stringLength >= ImageMagickMaxTextExtent) return(-1);

 return(WriteBlobStream(image, stringLength, (const unsigned char \*) string));
}