void GLES2DecoderImpl::RestoreCurrentRenderbufferBindings() {
  GLsizei max_renderbuffer_size = 0;
  glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &max_renderbuffer_size);

  if (bound_renderbuffer_ && bound_renderbuffer_->IsValidServiceId(max_renderbuffer_size)) {
    glBindRenderbufferEXT(
        GL_RENDERBUFFER,
        bound_renderbuffer_->service_id());
  }
}

// Add a new method to check the validity of service_id()
bool GLES2Renderbuffer::IsValidServiceId(GLsizei max_renderbuffer_size) const {
  return service_id_ >= 0 && service_id_ <= max_renderbuffer_size;
}