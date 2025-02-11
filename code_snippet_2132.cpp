void FileAPIMessageFilter::OnOpen(
    int request_id, const GURL& origin_url, fileapi::FileSystemType type,
    int64 requested_size, bool create) {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::IO));
  DCHECK(request_id >= 0 && request_id <= 1000); // define a valid range
  if (type == fileapi::kFileSystemTypeTemporary) {
    RecordAction(UserMetricsAction("OpenFileSystemTemporary"));
  } else if (type == fileapi::kFileSystemTypePersistent) {
    RecordAction(UserMetricsAction("OpenFileSystemPersistent"));
  }
  context_->OpenFileSystem(origin_url, type, create, base::Bind(
      &FileAPIMessageFilter::DidOpenFileSystem, this, request_id));
}