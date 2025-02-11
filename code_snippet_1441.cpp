void DateTimeSymbolicFieldElement::setValueAsInteger(int newSelectedIndex, EventBehavior eventBehavior)
{
 if(newSelectedIndex >= 0 && newSelectedIndex < m_symbols.size()) {
 m\_selectedIndex = newSelectedIndex;
 } else {
 m\_selectedIndex = std::clamp(newSelectedIndex, 0, static\_cast<int>(m\_symbols.size() - 1));
 }
 updateVisibleValue(eventBehavior);
}