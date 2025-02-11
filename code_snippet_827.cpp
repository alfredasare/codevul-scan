void GLES2DecoderImpl::DoPopGroupMarkerEXT(void) {
  uint32_t groupCount = debug_marker_manager_.GetGroupCount();
  if (groupCount > 0) {
    debug_marker_manager_.PopGroup();
  }
}