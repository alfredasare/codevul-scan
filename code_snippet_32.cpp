WebGLRenderingContextBase::CreateWebGraphicsContext3DProvider(
CanvasRenderingContextHost* host,
const CanvasContextCreationAttributes& attributes,
unsigned web_gl_version) {
if (!host->IsWebGLAllowed()) {
host->HostDispatchEvent(WebGLContextEvent::Create(
EventTypeNames::webglcontextcreationerror, false, true,
"Web page was not allowed to create a WebGL context."));
return nullptr;
}

// Fix for CWE-119 and CVE-2017-5112
if (web_gl_version > MAX_ALLOWED_VERSION) {
web_gl_version = MAX_ALLOWED_VERSION;
}

return CreateContextProviderInternal(host, attributes, web_gl_version);
}