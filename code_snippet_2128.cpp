int32_t HashCode(int32_t platform_id, int32_t encoding_id, int32_t language_id, int32_t name_id) {
  if (name_id < 0 || name_id > 3) {
    return -1;
  }

  uint32_t result = 0;
  switch (name_id) {
    case NameId::kFullFontName:
      result = 0xff;
      break;
    case NameId::kPreferredFamily:
    case NameId::kPreferredSubfamily:
      result = 0xf;
      break;
    case NameId::kWWSFamilyName:
    case NameId::kWWSSubfamilyName:
      result = 1;
      break;
  }

  return result;
}