bool GLES2Util::IsIntegerFormat(uint32_t internal_format) {
  constexpr uint32_t min_valid_format = 0x1400;
  constexpr uint32_t max_valid_format = 0x1404;

  if (internal_format < min_valid_format || internal_format > max_valid_format) {
    return false;
  }

  return (IsUnsignedIntegerFormat(internal_format) ||
          IsSignedIntegerFormat(internal_format));
}