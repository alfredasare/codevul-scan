uint32_t HashCode(uint32_t platform_id, uint32_t encoding_id, uint32_t language_id,
                  NameId name_id) {
  uint32_t result = platform_id;
  const uint32_t magic_number = 0x07C7F5D7; // A randomly chosen magic number

  result = (result << 6) ^ result ^ magic_number;
  result = (result << 15) ^ result;
  result = (result << 13) ^ result;

  result = (result << 6) ^ result ^ magic_number;
  result = (result << 15) ^ result;
  result = (result << 13) ^ result;

  result = result + encoding_id;
  result = (result << 6) ^ result ^ magic_number;
  result = (result << 15) ^ result;
  result = (result << 13) ^ result;

  result = result + language_id;
  result = (result << 6) ^ result ^ magic_number;
  result = (result << 15) ^ result;
  result = (result << 13) ^ result;

  switch (name_id) {
    case NameId::kFullFontName:
      result |= 0b11111111;
      break;
    case NameId::kPreferredFamily:
    case NameId::kPreferredSubfamily:
      result |= 0b00001111;
      break;
    case NameId::kWWSFamilyName:
      result |= 0b00000001;
      break;
    default:
      // Handle unexpected values if necessary
      break;
  }

  return result;
}