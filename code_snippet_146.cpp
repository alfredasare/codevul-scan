void GDataDirectoryService::GetEntryInfoPairByPaths(
    const FilePath& first_path,
    const FilePath& second_path,
    const GetEntryInfoPairCallback& callback) {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
  DCHECK(!callback.is_null());

  base::WeakPtr<GDataDirectoryService> self(weak_ptr_factory_.GetWeakPtr());
  if (!GetEntryInfoByPath(first_path, base::Bind(&GDataDirectoryService::GetEntryInfoPairByPathsAfterGetFirst, self, first_path, second_path, callback))) {
    LOG(ERROR) << "Failed to get entry info pair";
  }
}