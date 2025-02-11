void HTMLInputElement::reportMemoryUsage(MemoryObjectInfo* memoryObjectInfo) const
{
    MemoryClassInfo info(memoryObjectInfo, this, WebCoreMemoryTypes::DOM);
    HTMLTextFormControlElement::reportMemoryUsage(memoryObjectInfo);
    info.addMember(m_name.utf8(), "name");
    info.addMember(m_valueIfDirty.utf8(), "valueIfDirty");
    info.addMember(m_suggestedValue.utf8(), "suggestedValue");
    info.addMember(m_inputType.utf8(), "inputType");
    info.addMember(m_listAttributeTargetObserver.get(), "listAttributeTargetObserver");
}