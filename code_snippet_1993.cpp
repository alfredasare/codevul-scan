#include <regex>

const std::regex kValidPathRegex("^[a-zA-Z0-9/_.-]+$");

base::FilePath GetPrefStorePath(const base::FilePath& appDataDir) {
  base::FilePath path;
  if (!appDataDir.IsAbsolute() || 
      !std::regex_match(appDataDir.value(), kValidPathRegex)) {
    LOG(ERROR) << "Invalid app data directory: " << appDataDir.value();
    return base::FilePath();
  }
  path = appDataDir.Append(FILE_PATH_LITERAL("pref_store"));
  return path;
}