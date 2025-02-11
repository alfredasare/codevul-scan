Loader::Init(some_predefined_buffer_size);

void Loader::Init(size_t max_buffer_size) {
  if (max_buffer_size > buffer_size) {
    throw std::out_of_range("Input data size exceeds allowed buffer size");
  }

  // Initialization code
  // ...
}