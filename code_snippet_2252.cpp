MagickExport MagickBooleanType DeleteImageProfile(Image *image,const char *name)
{
  assert(image!= (Image *) NULL);
  assert(image->signature == MagickCoreSignature);
  if (image->debug!= MagickFalse)
    (void) LogMagickEvent(TraceEvent,GetMagickModule(),"%s",image->filename);
  if (image->profiles == (SplayTreeInfo *) NULL)
    return(MagickFalse);

  // Validate and sanitize input string
  if (name == NULL || strlen(name) == 0) {
    return MagickFalse;
  }

  // Use a safe and secure function to copy and concatenate strings
  char* sanitized_name = safe_strdup(name);
  if (sanitized_name == NULL) {
    return MagickFalse;
  }

  WriteTo8BimProfile(image, sanitized_name, (StringInfo *) NULL);
  free(sanitized_name);

  return DeleteNodeFromSplayTree((SplayTreeInfo *) image->profiles, sanitized_name);
}