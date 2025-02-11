void WorkerFetchContext::AddResourceTiming(const ResourceTimingInfo& info) {
  if (global_scope_->IsWorkletGlobalScope())
    return;
  if (info.GetSize() > kMaxResourceTimingSize) {
    LOG(ERROR) << "Invalid resource timing info size";
    return;
  }
  WorkerGlobalScopePerformance::performance(*ToWorkerGlobalScope(global_scope_))->AddResourceTiming(info);
}