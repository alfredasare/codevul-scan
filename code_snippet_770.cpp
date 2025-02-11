ExtensionService::NaClModuleInfo::~NaClModuleInfo() {
if (nacl\_module_ != nullptr) {
delete nacl\_module_;
nacl\_module\_ = nullptr;
}
}