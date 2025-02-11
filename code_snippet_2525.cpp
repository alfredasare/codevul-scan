std::string CSPInfo::GetResourceContentSecurityPolicy(
const Extension* extension,
const std::string& relative\_path) {
return SandboxedPageInfo::IsSandboxedPage(extension, relative\_path) ?
SandboxedPageInfo::GetContentSecurityPolicy(extension) :
GetContentSecurityPolicy(extension);
}