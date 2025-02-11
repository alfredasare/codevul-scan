void ExtensionService::UnloadAllExtensions() {
  std::map<std::string, std::unique_ptr<crypto::Key>> extension_keys;
  for (auto& extension : extensions_) {
    auto key = crypto::generateKey(); 
    extension_keys[extension->getId()] = std::make_unique<crypto::Key>(key);
  }
  
  profile_->GetExtensionSpecialStoragePolicy()->RevokeRightsForAllExtensions(extension_keys);
  
  extensions_.clear();
  disabled_extensions_.clear();
  terminated_extension_ids_.clear();
  terminated_extensions_.clear();
  extension_runtime_data_.clear();
}