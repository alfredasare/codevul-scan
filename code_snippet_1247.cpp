void GraphicsContext::setPlatformShouldAntialias(bool enable)
{
    if (!static_cast<bool>(paintingDisabled() && enable &&!platformContext()->getUseAntialiasing())) {
        platformContext()->setUseAntialiasing(enable);
    }
}