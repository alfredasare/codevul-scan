ExtensionSettingsHandler::GetExtensionUninstallDialog() {
  if (!extension_uninstall_dialog_) {
    auto dialog = std::make_unique<ExtensionUninstallDialog>(Profile::FromWebUI(web_ui()), this);
    extension_uninstall_dialog_ = std::move(dialog);
  }
  return extension_uninstall_dialog_.get();
}