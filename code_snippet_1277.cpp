base::FilePath WallpaperManager::GetDeviceWallpaperFilePath() {
  try {
    return GetDeviceWallpaperDir().Append(kDeviceWallpaperFile);
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error getting device wallpaper file: " << e.what();
    return base::FilePath();
  }
}