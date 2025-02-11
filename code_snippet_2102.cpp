GLSurfaceEGLOzoneX11::GLSurfaceEGLOzoneX11(EGLNativeWindowType window)
: NativeViewGLSurfaceEGL(validateWindow(window)) {}

EGLNativeWindowType GLSurfaceEGLOzoneX11::validateWindow(EGLNativeWindowType window) {
// Perform input validation here
return window;
}