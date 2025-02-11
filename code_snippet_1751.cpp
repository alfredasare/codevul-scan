MagickExport MagickBooleanType BilevelImage(Image *image, const double threshold)
{
  MagickBooleanType
    status;

  const char *image_path = image->filename; // Get the image path

  // Validate the input parameters
  if (image_path == NULL || strlen(image_path) == 0) {
    return MagickFalse; // Return an error if the input is invalid
  }

  // Sanitize the input path
  char sanitized_path[256];
  strcpy(sanitized_path, image_path);

  status = BilevelImageChannel(image, DefaultChannels, threshold);
  return status;
}