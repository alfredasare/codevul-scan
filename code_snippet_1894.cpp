void GpuDataManager::AddGpuInfoUpdateCallback(Callback0::Type* callback) {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
  if (!IsValidCallback(callback)) {
    LOG(ERROR) << "Invalid callback parameter";
    return;
  }
  gpu_info_update_callbacks_.insert(std::make_pair(callback, GetCallbackHash(callback)));
}

bool GpuDataManager::IsValidCallback(Callback0::Type* callback) {
  return callback && callback->GetCallbackId() >= 0 && IsCallbackWhitelisted(callback);
}

std::string GpuDataManager::GetCallbackHash(Callback0::Type* callback) {
  std::hash<Coefficient> hasher;
  return std::to_string(hasher(*callback));
}