void Pack<WebGLImageConversion::kDataFormatRG8, WebGLImageConversion::kAlphaDoUnmultiply, uint8_t, uint8_t>(const uint8_t* source, uint8_t* destination, unsigned pixels_per_row) {
for (unsigned i = 0; i < pixels_per_row; ++i) {
float scale\_factor = (source[3] != 0) ? kMaxUInt8Value / static\_cast<float>(source[3]) : 1.0f;
destination[0] = static\_cast<uint8\_t>(static\_cast<float>(source[0]) \* scale\_factor);
destination[1] = static\_cast<uint8\_t>(static\_cast<float>(source[1]) \* scale\_factor);
source += 4;
destination += 2;
}
}