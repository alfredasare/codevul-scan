void Instance::ConfigureNumberImageGenerator() {
  std::vector<pp::ImageData> num_images = GetThumbnailResources();
  if (num_images.size() > MAX_IMAGE_COUNT) {
    // Handle error or throw exception
  }
  pp::ImageData number_background = CreateResourceImage(PP_RESOURCEIMAGE_PDF_BUTTON_THUMBNAIL_NUM_BACKGROUND);
  std::vector<pp::ImageData> safe_num_images(num_images.begin(), num_images.end());
  number_image_generator_->Configure(number_background, safe_num_images, device_scale_);
}