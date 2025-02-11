c++
void GLES2DecoderImpl::DoPopGroupMarkerEXT(void) {
  if (!debug_marker_manager_.IsStackEmpty()) {
    debug_marker_manager_.PopGroup();
  } else {
    // Handle or log the error condition
  }
}