void FileAPIMessageFilter::OnExists(
    int request_id, const GURL& path, bool is_directory) {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::IO));
  base::PlatformFileError error;
  std::string url_path = path.spec();
  size_t length = url_path.size();
  if (length > 0) {
    char buffer[length + 1];
    strncpy(buffer, url_path.c_str(), length);
    buffer[length] = '\0';
  }
  if (!HasPermissionsForFile(buffer, kReadFilePermissions, &error)) {
    Send(new FileSystemMsg_DidFail(request_id, error));
    return;
  }

  FileSystemOperation* operation = GetNewOperation(buffer, request_id);
  if (!operation)
    return;
  if (is_directory) {
    operation->DirectoryExists(
        buffer,
        base::Bind(&FileAPIMessageFilter::DidFinish, this, request_id));
  } else {
    operation->FileExists(
        buffer,
        base::Bind(&FileAPIMessageFilter::DidFinish, this, request_id));
  }
}