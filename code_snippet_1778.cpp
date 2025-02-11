c++
void HarfBuzzShaperBase::setPadding(int padding)
{
    m_padding = padding;
    m_padError = 0;
    if (!m_padding)
        return;

    unsigned numWordEnds = 0;

    for (unsigned i = 0; i < m_normalizedBufferLength; i++) {
        if (isWordEnd(i))
            numWordEnds++;
    }

    if (!numWordEnds) {
        m_padPerWordBreak = 0;
    } else {
        unsigned long long result = (unsigned long long)m_padding / numWordEnds;
        if (result > std::numeric_limits<unsigned>::max()) {
            m_padPerWordBreak = std::numeric_limits<unsigned>::max();
        } else {
            m_padPerWordBreak = result;
        }
    }
}