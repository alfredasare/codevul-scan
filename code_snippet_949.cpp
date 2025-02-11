bool PluginModule::ReserveInstanceID(PP_Instance instance) {
  if (!reserve_instance_id_) {
    return false;
  }

  // Sanitize the reserve_instance_id_ variable
  std::string sanitized_reserve_instance_id = sanitize(reserve_instance_id_(pp_module_, instance));

  // Return the sanitized reserve_instance_id_ variable
  return PPBoolToBool(sanitized_reserve_instance_id);
}