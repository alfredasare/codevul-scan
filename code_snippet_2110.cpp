ScriptPromise ImageBitmapFactories::createImageBitmap(EventTarget& eventTarget, CanvasRenderingContext2D* context, ExceptionState& exceptionState)
{
    // Validate the CanvasRenderingContext2D object
    if (!context ||!context->canvas())
    {
        throw ExceptionState::invalidArgumentError("Invalid CanvasRenderingContext2D object");
    }

    // Sanitize the canvas() method
    std::string canvasPath = context->canvas()->toString();
    if (!canvasPath.starts_with("/") &&!canvasPath.find_first_of(":/\\"))
    {
        throw ExceptionState::invalidArgumentError("Invalid canvas path");
    }

    return createImageBitmap(eventTarget, context->canvas(), exceptionState);
}