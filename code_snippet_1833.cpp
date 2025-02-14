void Dispatcher::OnClearTabSpecificPermissions(
    const std::vector<std::string>& extension_ids,
    bool update_origin_whitelist,
    int tab_id,
    const std::shared_ptr<SecurityContext>& security_context) {
  for (const std::string& id : extension_ids) {
    const Extension* extension = RendererExtensionRegistry::Get()->GetByID(id);
    if (extension && security_context->CheckPermission("clear_permissions")) {
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
  }
}