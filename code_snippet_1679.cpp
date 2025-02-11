void Dispatcher::OnClearTabSpecificPermissions(
    const std::vector<std::string>& extension_ids,
    bool update_origin_whitelist,
    int tab_id) {
  for (size_t i = 0; i < extension_ids.size(); ++i) {
    const std::string& id = extension_ids[i];
    if (id.empty()) {
      continue;
    }
    try {
      const Extension* extension = RendererExtensionRegistry::Get()->GetByID(id);
      if (extension) {
        URLPatternSet old_effective =
            extension->permissions_data()->GetEffectiveHostPermissions();
        extension->permissions_data()->ClearTabSpecificPermissions(tab_id);
        if (update_origin_whitelist) {
          UpdateOriginPermissions(
              extension->url(),
              old_effective,
              extension->permissions_data()->GetEffectiveHostPermissions());
        }
      }
    } catch (const std::out_of_range& e) {
      // Handle the exception or log it for further investigation
    }
  }
}