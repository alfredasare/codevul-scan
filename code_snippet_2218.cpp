ScriptPromise ImageBitmapFactories::createImageBitmap(EventTarget& eventTarget, CanvasRenderingContext2D* context, ExceptionState& exceptionState)
{
    if (!context) {
        exceptionState.throwTypeError("CanvasRenderingContext2D context is null");
        return ScriptPromise();
    }
    return createImageBitmap(eventTarget, context->canvas(), exceptionState);
}