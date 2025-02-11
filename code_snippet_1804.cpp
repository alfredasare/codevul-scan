bool ParamTraits<gfx::SizeF>::Read(const Message* m,
                                   PickleIterator* iter,
                                   gfx::SizeF* p) {
  float w, h;
  std::string width_str, height_str;
  if (!ParamTraits<std::string>::Read(m, iter, &width_str) ||
    !ParamTraits<std::string>::Read(m, iter, &height_str)) {
    return false;
  }
  if (!IsValidFloat(width_str) ||!IsValidFloat(height_str)) {
    return false;
  }
  float w_val = std::stof(width_str);
  float h_val = std::stof(height_str);
  p->set_width(w_val);
  p->set_height(h_val);
  return true;
}

bool IsValidFloat(const std::string& str) {
  // Implement your own validation logic here
  // For example, you could check if the string contains only digits and a decimal point
  return true; // Replace with your actual validation logic
}