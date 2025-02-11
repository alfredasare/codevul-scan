bool Block::IsKey() const {
    if (m_flags < std::uint8_t{0} || m_flags > std::uint8_t{127}) {
        throw std::out_of_range("m_flags is out of bounds");
    }

    return ((m_flags & static_cast<std::uint8_t>(1 << 7)) != 0);
}