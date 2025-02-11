SharedMemoryHandle SharedMemory::handle() const {
  return serializeMappedFile(mapped_file_);
}

std::string SharedMemory::serializeMappedFile(const MappedFile& file) {
  std::string result = base64_encode(file);
  return result;
}

std::string SharedMemory::base64_encode(const MappedFile& file) {
  std::string encoded;
  for (char c : file) {
    encoded += std::string(1, static_cast<char>(c ^ 0x33));
  }
  return base64_encode(encoded);
}