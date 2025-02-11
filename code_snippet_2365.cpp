void FileAPIMessageFilter::OnOpen(
    int request_id, const GURL& origin_url, fileapi::FileSystemType type,
    int64 requested_size, bool create) {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::IO));
  context_->OpenFileSystem(origin_url, type, create, base::Bind(
      &FileAPIMessageFilter::DidOpenFileSystem, this, request_id, type));
}

void FileAPIMessageFilter::DidOpenFileSystem(
    int request_id, fileapi::FileSystemType type, bool result, const base::FilePath& path) {
  if (result) {
    if (type == fileapi::kFileSystemTypeTemporary) {
      RecordAction(UserMetricsAction("OpenFileSystemTemporary"));
    } else if (type == fileapi::kFileSystemTypePersistent) {
      RecordAction(UserMetricsAction("OpenFileSystemPersistent"));
    }
  }
  // Handle other aspects of the DidOpenFileSystem call here...
}