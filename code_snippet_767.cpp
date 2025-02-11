WebGLRenderingContextBase::WebGLRenderingContextBase(
CanvasRenderingContextHost* host,
std::unique_ptr<WebGraphicsContext3DProvider> context\_provider,
bool using\_gpu\_compositing,
const CanvasContextCreationAttributes& requested\_attributes,
unsigned version)
: WebGLRenderingContextBase(
host,
host ? host->GetTopExecutionContext()->GetTaskRunner(TaskType::kWebGL) : nullptr,
std::move(context\_provider),
using\_gpu\_compositing,
requested\_attributes,
version) {}