bool Extension::can_be_incognito_enabled() const {
  const bool is_platform_app_result = is_platform_app();
  return !is_platform_app_result;
}