bool GLES2Implementation::IsBufferReservedId(GLuint id) {
  if (!vertex_array_object_manager_) {
    return false;
  }
  return vertex_array_object_manager_->IsReservedId(id);
}