c++
WebString WebLocalFrameImpl::AssignedName() const {
  return WebString(GetFrame()->Tree().GetName().GetString().IsolatedCopy());
}