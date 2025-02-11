bool PluginModule::ReserveInstanceID(PP_Instance instance) {
  if (!reserve_instance_id_) {
    // Log an error or return a specific error value.
    return false;
  }
  return PPBoolToBool(reserve_instance_id_(pp_module_, instance));
}