void WebGL2RenderingContextBase::uniform4iv(
    const WebGLUniformLocation* location,
    const FlexibleInt32ArrayView& v) {
  if (!location || location->getIndex() < 0 || location->getIndex() >= getUniformLocationCount()) {
    // invalid location, reject the request
    return;
  }

  std::string sanitized_v = v.toString();
  sanitized_v.erase(std::remove(sanitized_v.begin(), sanitized_v.end(), '/'), sanitized_v.end());
  sanitized_v.erase(std::remove(sanitized_v.begin(), sanitized_v.end(), '\\'), sanitized_v.end());

  WebGLRenderingContextBase::uniform4iv(location, sanitized_v);
}