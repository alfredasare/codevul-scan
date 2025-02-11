PermissionsData::PermissionsData(
    const ExtensionId& extension_id,
    Manifest::Type manifest_type,
    Manifest::Location location,
    std::unique_ptr<const PermissionSet> initial_permissions)
    : extension_id_(extension_id),
      manifest_type_(manifest_type), 
      location_(location),
      active_permissions_unsafe_(std::move(initial_permissions)),
      withheld_permissions_unsafe_(std::make_unique<PermissionSet>()) {
    if (manifest_type_!= Manifest::Type::kNormal && 
        manifest_type_!= Manifest::Type::kDebug) {
        throw std::invalid_argument("Invalid manifest type");
    }
}