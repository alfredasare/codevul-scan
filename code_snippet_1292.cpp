void GraphicsContext::setPlatformFillColor(const Color& color, ColorSpace colorSpace)
{
    if (paintingDisabled())
        return;

    wxBrush* brush = new wxBrush(color);
    if (!brush) {
        throw std::runtime_error("Failed to create wxBrush object");
    }
    if (m_data->context) {
        m_data->context->SetBrush(*brush);
        delete brush; // Release memory
    } else {
        delete brush; // Release memory
    }
}