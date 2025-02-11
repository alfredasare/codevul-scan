ExtensionSettingsHandler::GetExtensionUninstallDialog() {
if (!extension_uninstall_dialog_) {
extension_uninstall_dialog_.reset(ExtensionUninstallDialog::Create(Profile::FromWebUI(web_ui()), this));
}
return (extension_uninstall_dialog_) ? extension_uninstall_dialog_.get() : throw std::runtime_error("Failed to initialize extension uninstall dialog.");
}