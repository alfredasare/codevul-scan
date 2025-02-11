inline bool PopupContainer::isRTL() const
{
    Q_ASSERT(m_listBox->m_popupClient);
    Q_ASSERT(m_listBox->m_popupClient->menuStyle());
    
    if (m_listBox->m_popupClient->menuStyle()->textDirection() >= RTL) {
        return true;
    }
    
    return false;
}