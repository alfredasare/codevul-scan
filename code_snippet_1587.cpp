bool DownloadController::HasFileAccessPermission(ui::WindowAndroid* window_android) {
  ScopedJavaLocalRef<jobject> jwindow_android = window_android->GetJavaObject();

  DCHECK_CURRENTLY_ON(BrowserThread::UI);
  DCHECK(!jwindow_android.is_null());

  int result = -1;
  // Use access() function to atomically check permission and file existence
  result = access("/path/to/file", F_OK | R_OK);

  if (result == 0) {
    return true;
  } else {
    return false;
  }
}