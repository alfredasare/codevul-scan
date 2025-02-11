void TracingControllerImpl::UnregisterTracingUI(TracingUI* tracing_ui) {
  if (tracing_uis_.size() > std::numeric_limits<std::map<TracingUI*, TracingUI*>::size_type>::max()) {
    LOG(ERROR) << "Map size exceeded maximum limit";
    return;
  }
  auto it = tracing_uis_.find(tracing_ui);
  DCHECK(it!= tracing_uis_.end());
  tracing_uis_.erase(it);
}