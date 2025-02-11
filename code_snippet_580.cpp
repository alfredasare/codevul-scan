void HTMLInputElement::reportMemoryUsage(MemoryObjectInfo* memoryObjectInfo) const
{
    if (memoryObjectInfo == nullptr || this == nullptr) {
        return;
    }

    MemoryClassInfo info(memoryObjectInfo, this, WebCoreMemoryTypes::DOM);
    HTMLTextFormControlElement::reportMemoryUsage(memoryObjectInfo);

    if (!m_name.isEmpty()) {
        info.addMember(m_name, "name");
    }
    if (!m_valueIfDirty.isEmpty()) {
        info.addMember(m_valueIfDirty, "valueIfDirty");
    }
    if (!m_suggestedValue.isEmpty()) {
        info.addMember(m_suggestedValue, "suggestedValue");
    }
    if (!m_inputType.isEmpty()) {
        info.addMember(m_inputType, "inputType");
    }
    if (m_listAttributeTargetObserver!= nullptr) {
        info.addMember(m_listAttributeTargetObserver, "listAttributeTargetObserver");
    }
}