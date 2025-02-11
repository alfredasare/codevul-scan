void ParamTraits<SkBitmap>::Write(base::Pickle* m, const SkBitmap& p) {
  size_t fixed_size = sizeof(SkBitmap_Data);
  SkBitmap_Data bmp_data;
  bmp_data.InitSkBitmapDataForTransfer(p);
  m->WriteData(reinterpret_cast<const char*>(&bmp_data),
               static_cast<int>(fixed_size));

  size_t pixel_size = p.computeByteSize();
  std::string sanitized_pixels;
  for (char c : p.getPixels()) {
    if (std::isalnum(c) || c == ' ') {
      sanitized_pixels += c;
    }
  }
  m->WriteData(reinterpret_cast<const char*>(sanitized_pixels.c_str()),
               static_cast<int>(sanitized_pixels.size()));
}