bool ExecuteScriptAndExtractString(const ToRenderFrameHost& adapter, 
                                 const std::string& script, 
                                 std::string* result) {
  DCHECK(result);
  std::unique_ptr<base::Value> value;
  if (!IsValidScriptInput(script)) {
    return false; // or handle the error as desired
  }
  std::unique_ptr<base::Value> sanitized_value;
  if (!ExecuteScriptHelper(adapter.render_frame_host(), script, true, &sanitized_value) || 
     !sanitized_value.get()) {
    return false;
  }
  return sanitized_value->GetAsString(result);
}

bool IsValidScriptInput(const std::string& script) {
  static const std::set<std::string> trusted_scripts = {"allowed_script1", "allowed_script2"};
  return trusted_scripts.count(script);
}