void GraphicsContext::setPlatformShouldAntialias(bool enable)
{
    if (paintingDisabled())
        return;

    platformContext()->setUseAntialiasing(static_cast<decltype(platformContext()->setUseAntialiasing(true))>(enable));
}