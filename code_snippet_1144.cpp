void GraphicsContext::clearRect(const FloatRect& rect) 
{
    if (!isValidFloatRect(rect)) {
        throw InvalidArgumentException("Invalid rectangle coordinates");
    }

    // Use validated and sanitized rect values
    m_rect = rect;
}

bool GraphicsContext::isValidFloatRect(const FloatRect& rect) {
    // Validate rect.x, rect.y, rect.width, and rect.height
    // Check for valid range, format, and other constraints
    return true; // Replace with actual validation logic
}