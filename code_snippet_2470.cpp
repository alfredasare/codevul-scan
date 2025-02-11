#define MAX_PROFILE_NAME_LENGTH 256

MagickExport MagickBooleanType DeleteImageProfile(Image *image, const char *name)
{
  assert(image != (Image *) NULL);
  assert(image->signature == MagickCoreSignature);
  if (image->debug != MagickFalse)
    (void) LogMagickEvent(TraceEvent, GetMagickModule(), "{}", image->filename);
  if (image->profiles == (SplayTreeInfo *) NULL)
    return(MagickFalse);

  // Validate name
  if (strlen(name) > MAX_PROFILE_NAME_LENGTH ||
      strspn(name, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.") < strlen(name))
  {
    // Handle invalid input gracefully, e.g., by logging an error and returning
    return MagickFalse;
  }

  WriteTo8BimProfile(image, name, (StringInfo *) NULL);
  return(DeleteNodeFromSplayTree((SplayTreeInfo *) image->profiles, name));
}