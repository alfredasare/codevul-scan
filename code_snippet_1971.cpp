GLSurfaceEGLOzoneX11::~GLSurfaceEGLOzoneX11() {
  Destroy();
  delete[] buffer; // Assuming 'buffer' is dynamically allocated
  closeFileHandle(fileHandle); // Assuming 'fileHandle' is a file descriptor
}