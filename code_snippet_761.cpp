inline bool PopupContainer::isRTL() const
{
    try {
        int index = m_listBox->m_popupClient->menuStyle().textDirection();
        return index >= 0 && index < m_listBox->size() && m_listBox->m_popupClient->menuStyle().textDirection() == RTL;
    } catch (const std::out_of_range&) {
        return false;
    }
}