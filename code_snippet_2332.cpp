const std::string CSPInfo::GetResourceContentSecurityPolicy(
    const Extension* extension,
    const std::string& relative_path) {
  std::string policy = SandboxedPageInfo::IsSandboxedPage(extension, relative_path)?
      SandboxedPageInfo::GetContentSecurityPolicy(extension) :
      GetContentSecurityPolicy(extension);
  return policy; // Returning a copy of the policy
}