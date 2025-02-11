int32_t HTMLFormControlElement::GetAxId() const {
  AXObjectCache* cache = GetDocument().ExistingAXObjectCache();
  if (cache != nullptr) {
    return cache->GetAXID(const_cast<HTMLFormControlElement*>(this));
  }
  return 0;
}