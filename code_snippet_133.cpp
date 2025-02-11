void Framebuffer::OnDidRenderTo() const {
  for (AttachmentMap::const_iterator it = attachments_.begin(), endIt = attachments_.end();
       it != endIt; ++it) {
    it->second->OnDidRenderTo();
  }
}