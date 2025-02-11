void ModuleSystem::OnDidAddPendingModule(
    const std::string& id,
    const std::vector<std::string>& dependencies) {
  bool module_system_managed = source_map_->Contains(id);

  gin::ModuleRegistry* registry =
      gin::ModuleRegistry::From(context_->v8_context());
  DCHECK(registry);

  // Validate and limit the dependencies vector
  std::vector<std::string> validated_dependencies;
  for (const auto& dependency : dependencies) {
    if (!dependency.empty() && dependency.size() <= MAX_DEPENDENCY_SIZE) {
      validated_dependencies.push_back(dependency);
    }
  }

  for (const auto& dependency : validated_dependencies) {
    if (registry->available_modules().count(dependency) == 0 &&
        (module_system_managed || source_map_->Contains(dependency))) {
      LoadModule(dependency);
    }
  }
  registry->AttemptToLoadMoreModules(GetIsolate());
}