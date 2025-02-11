++
void ExecuteCodeInTabFunction::DidLoadFile(bool success,
                                         const std::string& data) {
  std::string function_name = name();
  const extensions::Extension* extension = GetExtension();

  if (success &&
      function_name == TabsInsertCSSFunction::function_name() &&
      extension!= NULL &&
      data.find(extensions::MessageBundle::kMessageBegin)!= std::string::npos) {
    if (IsValidData(data)) {
      BrowserThread::PostTask(BrowserThread::FILE, FROM_HERE,
                             base::Bind(&ExecuteCodeInTabFunction::LocalizeCSS, this,
                                        data,
                                        extension->id(),
                                        extension->path(),
                                        extensions::LocaleInfo::GetDefaultLocale(extension)));
    } else {
      DidLoadAndLocalizeFile(success, data);
    }
  } else {
    DidLoadAndLocalizeFile(success, data);
  }
}

bool ExecuteCodeInTabFunction::IsValidData(const std::string& data) {
  static const std::set<char> allowed_chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '-', '_', '+','', '\'', '\"', '/', '\\', '[', ']'}; // Define allowed characters
  return std::all_of(data.begin(), data.end(), [&allowed_chars](char c) {
    return allowed_chars.count(c) > 0;
  });
}