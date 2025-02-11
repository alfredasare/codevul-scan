WebGLTransformFeedback* WebGL2RenderingContextBase::createTransformFeedback() {
if (isContextLost())
return nullptr;
WebGLTransformFeedback* tf = WebGLTransformFeedback::Create(this,
WebGLTransformFeedback::TFTypeUser);
if (!tf)
return nullptr;
return tf;
}