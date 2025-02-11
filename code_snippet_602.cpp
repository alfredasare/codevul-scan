CreateContextProviderOnWorkerThread(
    Platform::ContextAttributes context_attributes,
    Platform::GraphicsInfo* gl_info,
    bool* using_gpu_compositing,
    const std::string& url) {
  if (!context_attributes.IsValid()) {
    LOG(ERROR) << "Invalid context attributes";
    return nullptr;
  }
  if (!gl_info) {
    LOG(ERROR) << "Invalid graphics info";
    return nullptr;
  }
  if (using_gpu_compositing == nullptr) {
    LOG(ERROR) << "Invalid using_gpu_compositing";
    return nullptr;
  }
  if (url.empty()) {
    LOG(ERROR) << "Invalid URL";
    return nullptr;
  }

  scoped_refptr<WebTaskRunner> task_runner =
      Platform::Current()->MainThread()->GetWebTaskRunner();
  if (!task_runner) {
    LOG(ERROR) << "Failed to get task runner";
    return nullptr;
  }

  ContextProviderCreationInfo creation_info;
  creation_info.context_attributes = context_attributes;
  creation_info.gl_info = gl_info;
  creation_info.url = url;
  creation_info.using_gpu_compositing = using_gpu_compositing;
  PostCrossThreadTask(*task_runner, FROM_HERE,
                      CrossThreadBind(&CreateContextProviderOnMainThread,
                                      CrossThreadUnretained(&creation_info),
                                      CrossThreadUnretained(&waitable_event)));
  waitable_event.Wait();
  return std::move(creation_info.created_context_provider);
}