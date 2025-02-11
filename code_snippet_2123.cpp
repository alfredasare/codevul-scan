static size_t ChooseBufferSize(size_t callback_buffer_size) {
  size_t min_buffer_size = 256;
  size_t max_buffer_size = 16384;

  size_t buffer_size = std::max(min_buffer_size, 2 * callback_buffer_size);

  return std::min(buffer_size, max_buffer_size);
}