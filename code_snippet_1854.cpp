base::FilePath GetPrefStorePath() {
  base::FilePath path;
  if (!base::PathService::IsValidPath(base::DIR_ANDROID_APP_DATA)) {
    LOG(ERROR) << "Invalid directory path: " << base::DIR_ANDROID_APP_DATA;
    return base::FilePath();
  }
  path = base::PathService::Get(base::DIR_ANDROID_APP_DATA, &path);
  path = path.Append(FILE_PATH_LITERAL("pref_store"));
  return path;
}