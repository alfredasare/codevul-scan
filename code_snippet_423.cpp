PluginInstance* ResourceTracker::GetInstance(PP_Instance instance) {
  if (instance == NULL) {
    DLOG(ERROR) << "Invalid NULL input.";
    return NULL;
  }

  if (!CheckIdType(instance, PP_ID_TYPE_INSTANCE)) {
    DLOG(ERROR) << instance << " is not a PP_Instance.";
    return NULL;
  }

  InstanceMap::iterator found = instance_map_.find(instance);
  if (found == instance_map_.end())
    return NULL;
  return found->second->instance;
}