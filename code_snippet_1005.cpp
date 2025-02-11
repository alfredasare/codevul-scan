void Pack<WebGLImageConversion::kDataFormatRG8,
          WebGLImageConversion::kAlphaDoUnmultiply,
          uint8_t,
          uint8_t>(const uint8_t* source,
                   uint8_t* destination,
                   unsigned pixels_per_row) {
  for (unsigned i = 0; i < pixels_per_row; ++i) {
    if (i * 4 >= pixels_per_row || i * 2 >= pixels_per_row) {
      return;  // Handle out-of-bounds condition
    }
    float scale_factor = (source + 3)? kMaxUInt8Value / static_cast<float>((*source)[3]) : 1.0f;
    destination[0] = static_cast<uint8_t>(static_cast<float>((*source)[0]) * scale_factor);
    destination[1] = static_cast<uint8_t>(static_cast<float>((*source)[1]) * scale_factor);
    source += 4;
    destination += 2;
  }
}