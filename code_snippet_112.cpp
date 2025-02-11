void WebGL2RenderingContextBase::clearBufferfv(
    GLenum buffer,
    GLint drawbuffer,
    MaybeShared<DOMFloat32Array> value,
    GLuint src_offset) {
  if (isContextLost() ||
      !ValidateClearBuffer("clearBufferfv", buffer, value.View()->length(),
                           src_offset))
    return;

  const size_t data_length = value.View()->length() * sizeof(float);
  if (src_offset >= data_length / sizeof(float)) {
    // Handle error scenario
    return;
  }

  ScopedRGBEmulationColorMask emulation_color_mask(this, color_mask_,
                                                   drawing_buffer_.get());

  ContextGL()->ClearBufferfv(buffer, drawbuffer,
                             value.View()->DataMaybeShared() + src_offset);
  MarkContextChanged(kCanvasChanged);
  UpdateBuffersToAutoClear(kClearBufferfv, buffer, drawbuffer);
}