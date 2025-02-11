ImageBitmap* ImageBitmap::create(ImageData* data, Optional<IntRect> cropRect, const ImageBitmapOptions& options) {
  if (!data || data->getSize().width <= 0 || data->getSize().height <= 0) {
    return nullptr;
  }

  if (cropRect.has_value() && (cropRect->x < 0 || cropRect->y < 0 || cropRect->width > data->getSize().width || cropRect->height > data->getSize().height)) {
    return nullptr;
  }

  return new ImageBitmap(data, cropRect, options);
}