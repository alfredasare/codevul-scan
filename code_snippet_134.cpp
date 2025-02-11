GLvoid StubGLVertexAttribPointer(GLuint indx, GLint size, GLenum type,
                                 GLboolean normalized, GLsizei stride,
                                 const void* ptr) {
    if (stride > INT_MAX) {
        // Handle error: stride value exceeds maximum allowed value
        return;
    }

    glVertexAttribPointer(indx, size, type, normalized, (GLsizei)stride, ptr);
}