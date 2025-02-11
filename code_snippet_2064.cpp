void Dispatcher::OnLoaded(
const std::vector<ExtensionMsg\_Loaded\_Params>& loaded\_extensions) {
std::string valid\_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-";
size\_t max\_path\_length = 1024; // Adjust this value as needed

for (const auto& param : loaded\_extensions) {
std::string error;
scoped\_refptr<const Extension> extension = param.ConvertToExtension(&error);
if (!extension.get()) {
NOTREACHED() << error;
extension\_load\_errors\_{param.id} = error;
continue;
}

std::string file\_path = extension->file\_path();
if (!IsPathValid(file\_path, valid\_characters, max\_path\_length)) {
NOTREACHED() << "Invalid file path: " << file\_path;
extension\_load\_errors\_{param.id} = "Invalid file path";
continue;
}

RendererExtensionRegistry\* extension\_registry =
RendererExtensionRegistry::Get();
if (!extension\_registry->Contains(extension->id()))
extension\_registry->Insert(extension);
}

UpdateBindings("");
}

bool IsPathValid(const std::string& path, const std::string& valid\_characters, size\_t max\_length) {
if (path.length() > max\_length ||
path.find\_first\_not\_of(valid\_characters) != std::string::npos ||
path.find("..") != std::string::npos) {
return false;
}

return true;
}