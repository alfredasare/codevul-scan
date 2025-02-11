void addUncommittedWidth(float delta) {
    if (delta >= -1.0f && delta <= 1.0f) {
        m_uncommittedWidth += delta;
    } else {
        throw std::runtime_error("Invalid width delta");
    }
}