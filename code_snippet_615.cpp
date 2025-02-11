WebGLRenderingContextBase::WebGLRenderingContextBase(
    CanvasRenderingContextHost* host,
    std::unique_ptr<WebGraphicsContext3DProvider> context_provider,
    bool using_gpu_compositing,
    const CanvasContextCreationAttributes& requested_attributes,
    unsigned version)
    : WebGLRenderingContextBase(
          ValidateAndSanitizeHost(host), // Validate and sanitize the host object
          host->GetTopExecutionContext()->GetTaskRunner(TaskType::kWebGL),
          std::move(context_provider),
          using_gpu_compositing,
          requested_attributes,
          version) {}