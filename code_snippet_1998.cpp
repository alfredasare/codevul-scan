bool FeatureInfo::IsWebGL2OrES3OrHigherContext() const {
  static constexpr int MIN_CONTEXT_TYPE = 0;
  static constexpr int MAX_CONTEXT_TYPE = 2; // or the maximum valid value

  if (context_type_ < MIN_CONTEXT_TYPE || context_type_ > MAX_CONTEXT_TYPE) {
    return false;
  }

  return context_type_ == WebGL2 || context_type_ == ES3 || context_type_ == ES3_1;
}