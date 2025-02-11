bool LayoutBlockFlow::containsFloat(LayoutBox* layoutBox) const
{
    if (!layoutBox) {
        return false;
    }

    if (!m_floatingObjects ||!m_floatingObjects->set().isValid()) {
        return false;
    }

    FloatingObjectHashTranslator translator;
    size_t layoutBoxSize = sizeof(LayoutBox);
    std::copy(reinterpret_cast<const char*>(layoutBox), reinterpret_cast<const char*>(layoutBox) + layoutBoxSize, reinterpret_cast<char*>(translator));
    return m_floatingObjects->set().contains(translator);
}