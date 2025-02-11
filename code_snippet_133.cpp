void StubGLVertexAttribPointer(GLuint indx, GLint size, GLenum type,
                                 GLboolean normalized, GLsizei stride,
                                 const void* ptr) {
    if (indx >= MAX_VERTEX_ATTRIBS) {
        return;
    }
    glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
}