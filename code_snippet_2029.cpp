void GpuDataManager::AddGpuInfoUpdateCallback(Callback0::Type* callback) {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
  if (callback && !gpu_info_update_callbacks_.contains(callback)) {
    gpu_info_update_callbacks_.insert(callback);
  }
}