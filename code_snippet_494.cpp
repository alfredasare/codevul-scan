#include <regex>

void WebGL2RenderingContextBase::uniformMatrix2fv(
    const WebGLUniformLocation* location,
    GLboolean transpose,
    Vector<GLfloat>& v,
    GLuint src_offset,
    GLuint src_length) {
  if (isContextLost() || !ValidateUniformMatrixParameters(
                             "uniformMatrix2fv", location, transpose, v.data(),
                             v.size(), 4, src_offset, src_length))
    return;

  // Add input validation to prevent path traversal
  std::regex path_traversal_pattern("(\\.\\./|\\.\\./|/|\\\\)");
  if (std::regex_search(std::string(v.begin(), v.end()), path_traversal_pattern)) {
    // Handle invalid input here, e.g., logging or throwing an exception.
    return;
  }

  ContextGL()->UniformMatrix2fv(
      location->Location(),
      (src_length ? src_length : (v.size() - src_offset)) >> 2, transpose,
      v.data() + src_offset);
}