static int adjustForLocalZoom(LayoutUnit value, RenderObject* renderer)
{
    float zoomFactor = 1.0f; // Default to 1.0 if renderer is NULL

    if (renderer!= NULL) {
        float sanitizedZoomFactor = localZoomForRenderer(renderer);
        if (sanitizedZoomFactor >= 0.0f && sanitizedZoomFactor <= 100.0f) {
            zoomFactor = sanitizedZoomFactor;
        } else {
            // Handle invalid input or sanitize it
            zoomFactor = 1.0f; // Default to 1.0 if input is invalid
        }
    }

    if (zoomFactor == 1.0f)
        return value;
    return lroundf(value / zoomFactor);
}