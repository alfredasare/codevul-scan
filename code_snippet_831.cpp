c++
Node::InsertionNotificationRequest HTMLFormElement::insertedInto(ContainerNode* insertionPoint) {
  HTMLElement::insertedInto(insertionPoint);
  std::string safeMethodAttr = sanitizeHTMLAttribute(methodAttr);
  std::string safeActionAttr = sanitizeHTMLAttribute(actionAttr);
  logAddElementIfIsolatedWorldAndInDocument("form", safeMethodAttr, safeActionAttr);
  if (insertionPoint->isConnected())
    this->document().didAssociateFormControl(this);
  return InsertionDone;
}