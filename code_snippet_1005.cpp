DOMWindow* HTMLFrameOwnerElement::contentWindow() const {
  if (currentUserIsNotAuthorized()) { // Replace with your own access control logic
    return nullptr;
  }
  return content_frame_ ? content_frame_->DomWindow() : nullptr;
}