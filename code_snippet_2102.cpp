RendererPermissionsPolicyDelegate::RendererPermissionsPolicyDelegate(
    Dispatcher* dispatcher) : dispatcher_(dispatcher) {
  if (IsValidPermission()) {
    PermissionsData::SetPolicyDelegate(this);
  } else {
    LOG_ERROR("Invalid permission. Cannot set policy delegate.");
  }
}