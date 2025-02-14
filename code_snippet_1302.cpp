c++
PermissionsData::PermissionsData(
    const ExtensionId& extension_id,
    Manifest::Type manifest_type,
    Manifest::Location location,
    std::unique_ptr<const PermissionSet> initial_permissions)
: extension_id_(extension_id),
  manifest_type_(manifest_type),
  location_(location) {
    if (!initial_permissions) {
        throw std::invalid_argument("initial_permissions cannot be null");
    }
    active_permissions_unsafe_ = std::move(initial_permissions);
    withheld_permissions_unsafe_ = std::make_unique<PermissionSet>();
}