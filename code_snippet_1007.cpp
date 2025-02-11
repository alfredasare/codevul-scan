MagickExport Image *ReadInlineImage(const ImageInfo *image_info,
  const char *content,ExceptionInfo *exception)
{
  //...

  size_t decoded_length = Base64DecodeMaxLength(content);
  unsigned char *blob = (unsigned char *) RelinquishMagickMemory(Malloc(decoded_length + 1));
  size_t length = Base64Decode(content, &decoded_length, blob);

  if (length > decoded_length) {
    ThrowReaderException(CorruptImageError, "CorruptImage");
  }

  blob[decoded_length] = '\0'; // null-terminate the string
  //...
}