std::unique_ptr<base::DictionaryValue> CreateFileSystemValue(
    DevToolsFileHelper::FileSystem file_system) {
  if (file_system.type.empty() || file_system.file_system_name.empty() ||
      file_system.root_url.empty() || file_system.file_system_path.empty()) {
    // Handle error case by returning an empty unique_ptr or throwing an exception
    return nullptr;
  }
  
  auto file_system_value = base::MakeUnique<base::DictionaryValue>();
  file_system_value->SetString("type", file_system.type);
  file_system_value->SetString("fileSystemName", file_system.file_system_name);
  file_system_value->SetString("rootURL", file_system.root_url);
  file_system_value->SetString("fileSystemPath", file_system.file_system_path);
  return file_system_value;
}