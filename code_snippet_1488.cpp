static CrostiniUpgraderFactory* GetInstance() {
  static std::once_flag factory_creation_flag;
  std::call_once(factory_creation_flag, [](){
    factory_ = std::make_unique<CrostiniUpgraderFactory>();
  });
  return factory_.get();
}