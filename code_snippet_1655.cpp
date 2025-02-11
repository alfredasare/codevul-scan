static CrostiniUpgraderFactory* GetInstance(const std::string& input) {
  if (input.empty()) {
    return nullptr;
  }
  static base::NoDestructor<CrostiniUpgraderFactory> factory;
  return factory.get();
}