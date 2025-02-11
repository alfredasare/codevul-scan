c++
std::unique_ptr<base::DictionaryValue> CreateFileSystemValue(
    DevToolsFileHelper::FileSystem file_system) {
  auto file_system_value = base::MakeUnique<base::DictionaryValue>();

  // Validate and sanitize input
  file_system.type = SanitizeFileSystemType(file_system.type);
  file_system.file_system_name = SanitizeFileSystemName(file_system.file_system_name);
  file_system.root_url = SanitizeUrl(file_system.root_url);
  file_system.file_system_path = SanitizeFileSystemPath(file_system.file_system_path);

  file_system_value->SetString("type", file_system.type);
  file_system_value->SetString("fileSystemName", file_system.file_system_name);
  file_system_value->SetString("rootURL", file_system.root_url);
  file_system_value->SetString("fileSystemPath", file_system.file_system_path);
  return file_system_value;
}

std::string SanitizeFileSystemType(const std::string& type) {
  // Implement your own sanitization logic here
  return type; // Replace with actual sanitization logic
}

std::string SanitizeFileSystemName(const std::string& name) {
  // Implement your own sanitization logic here
  return name; // Replace with actual sanitization logic
}

std::string SanitizeUrl(const std::string& url) {
  // Implement your own sanitization logic here
  return url; // Replace with actual sanitization logic
}

std::string SanitizeFileSystemPath(const std::string& path) {
  // Implement your own sanitization logic here
  return path; // Replace with actual sanitization logic
}