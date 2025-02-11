PluginInstance* ResourceTracker::GetInstance(PP_Instance instance) {
  DLOG_IF(ERROR,!CheckIdType(instance, PP_ID_TYPE_INSTANCE))
      << instance << " is not a PP_Instance.";
  if (instance_map_.find(instance) == instance_map_.end()) {
    return NULL;
  }
  return instance_map_[instance]->instance;
}