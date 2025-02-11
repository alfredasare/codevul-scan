c++
void GraphicsContext::clearRect(const FloatRect& rect) 
{
    if (rect.x < 0) rect.x = 0;
    if (rect.y < 0) rect.y = 0;
    if (rect.width <= 0) return;
    if (rect.height <= 0) return;

    const auto max_x = std::min(this->width(), static_cast<decltype(this->width())>(rect.x + rect.width));
    const auto max_y = std::min(this->height(), static_cast<decltype(this->height())>(rect.y + rect.height));

    for (decltype(this->width()) y = rect.y; y < max_y; ++y)
    {
        for (decltype(this->width()) x = rect.x; x < max_x; ++x)
        {
            // Implement the actual clearing operation here
            // ...
        }
    }
}