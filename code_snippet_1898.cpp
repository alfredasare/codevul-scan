MagickBooleanType BilevelImage(Image *image, const double threshold) {
  MagickBooleanType status;

  if (!image) {
    fprintf(stderr, "Error: Image pointer cannot be NULL\n");
    return(MagickFalse);
  }

  if (threshold < 0.0 || threshold > 1.0) {
    fprintf(stderr, "Error: Threshold value must be between 0.0 and 1.0\n");
    return(MagickFalse);
  }

  status = BilevelImageChannel(image, DefaultChannels, threshold);
  return(status);
}