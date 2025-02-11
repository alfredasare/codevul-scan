ExtensionSettingsHandler::~ExtensionSettingsHandler() {
  if (load_extension_dialog_ != nullptr)
    load_extension_dialog_->ListenerDestroyed();

  registrar_.RemoveAll();
}