MagickExport FILE *GetImageInfoFile(const ImageInfo *image_info)
{
  char *file_path = image_info->file;
  char *normalized_path = realpath(file_path, NULL);
  if (normalized_path == NULL) {
    return NULL;
  }
  if (strncmp(normalized_path, "/path/to/trusted/directory", strlen("/path/to/trusted/directory"))!= 0) {
    free(normalized_path);
    return NULL;
  }
  return fopen(normalized_path, "r");
}