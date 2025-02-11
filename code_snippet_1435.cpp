bool DownloadController::HasFileAccessPermission(ui::WindowAndroid* window_android) {
  ScopedJavaLocalRef<jobject> jwindow_android = window_android->GetJavaObject();

  DCHECK_CURRENTLY_ON(BrowserThread::UI);
  DCHECK(!jwindow_android.is_null());

  JNIEnv* env = base::android::AttachCurrentThread();

  // Validate and sanitize the GetJavaObject()->Controller(env) variable
  const std::string controllerStr = GetJavaObject()->Controller(env).toString();
  std::string sanitizedController = SanitizePath(controllerStr);

  // Validate and sanitize the jwindow_android variable
  const std::string jwindow_android_str = jwindow_android.toString();
  std::string sanitizedJwindowAndroid = SanitizePath(jwindow_android_str);

  return Java_DownloadController_hasFileAccess(env, sanitizedController.c_str(), sanitizedJwindowAndroid.c_str());
}

std::string SanitizePath(const std::string& path) {
  std::string sanitizedPath = path;
  sanitizedPath.erase(std::remove(sanitizedPath.begin(), sanitizedPath.end(), '/'), sanitizedPath.end());
  return sanitizedPath;
}