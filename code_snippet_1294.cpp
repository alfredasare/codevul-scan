void DateTimeSymbolicFieldElement::setValueAsInteger(int newSelectedIndex, EventBehavior eventBehavior)
{
    if (newSelectedIndex < 0 || newSelectedIndex >= static_cast<int>(m_symbols.size()))
    {
        newSelectedIndex = std::max(0, std::min(static_cast<int>(m_symbols.size()) - 1, newSelectedIndex));
    }
    m_selectedIndex = newSelectedIndex;
    updateVisibleValue(eventBehavior);
}