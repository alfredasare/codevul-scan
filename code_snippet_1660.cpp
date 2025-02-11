bool TraceEventTestFixture::FindNonMatchingValue(const std::string& key,
                                                const std::string& value) {
  std::vector<JsonKeyValue> key_values = {
    {key, value, IS_NOT_EQUAL},
    {"", "", IS_EQUAL}
  };
  return FindMatchingTraceEntry(key_values);
}

bool TraceEventTestFixture::FindMatchingTraceEntry(const std::vector<JsonKeyValue>& key_values) {
  json_object* object = /* get json object */;

  for (const auto& key_value : key_values) {
    json_object* iter;
    if (json_object_object_get_ex(object, key_value.key.c_str(), &iter)) {
      if (json_is_string(iter) && !strcmp(json_string_get_text(iter), key_value.value.c_str())) {
        if (key_value.comparison == IS_NOT_EQUAL) {
          return false;
        }
      } else if (key_value.comparison == IS_EQUAL) {
        return true;
      }
    }
  }

  return false;
}