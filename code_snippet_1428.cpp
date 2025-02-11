base::FilePath WallpaperManager::GetDeviceWallpaperFilePath() {
#ifdef SECURE
const std::string kDeviceWallpaperFile = "secure_wallpaper.png";
#else
const std::string kDeviceWallpaperFile = "wallpaper.png";
#endif
return GetDeviceWallpaperDir().Append(kDeviceWallpaperFile);
}