void Dispatcher::OnLoaded(
    const std::vector<ExtensionMsg_Loaded_Params>& loaded_extensions) {
  for (const auto& param : loaded_extensions) {
    std::string error;
    scoped_refptr<const Extension> extension = param.ConvertToExtension(&error);
    if (!extension.get()) {
      NOTREACHED() << error;
      extension_load_errors_[param.id] = error;
      continue;
    }

    std::string extension_id = extension->id();
    RendererExtensionRegistry* extension_registry =
        RendererExtensionRegistry::Get();
    if (!extension_registry->insert({extension_id, extension}).second) {
      // Insert the extension only if it's not already present
      extension_registry->Insert(extension);
    }
  }

  UpdateBindings("");
}