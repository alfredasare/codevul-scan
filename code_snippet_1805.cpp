void CrosLibrary::TestApi::SetSyslogsLibrary(SyslogsLibrary* library, bool own) {
  if (!library) {
    return;
  }

  SyslogsLibrary* copiedLibrary = new SyslogsLibrary(*library);
  library_->syslogs_lib_.SetImpl(copiedLibrary, own);
}