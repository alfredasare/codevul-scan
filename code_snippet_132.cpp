void Framebuffer::OnDidRenderTo() const {
  for (AttachmentMap::const_iterator it = attachments_.begin();
       it!= attachments_.end(); ++it) {
    std::string attachmentPath = it->first;
    if (!isValidAttachmentPath(attachmentPath)) {
      continue; // Skip invalid attachments
    }
    if (!isAllowedDirectory(attachmentPath) ||!isAllowedExtension(attachmentPath)) {
      continue; // Skip attachments with unauthorized directories or extensions
    }
    it->second->OnDidRenderTo();
  }
}

bool isValidAttachmentPath(const std::string& path) {
  return path.find("/allowed/directory/") == 0;
}

bool isAllowedDirectory(const std::string& path) {
  static const std::set<std::string> allowedDirectories = {"allowed/directory1", "allowed/directory2"};
  return allowedDirectories.find(path.substr(0, path.find('/')))!= allowedDirectories.end();
}

bool isAllowedExtension(const std::string& path) {
  static const std::set<std::string> allowedExtensions = {".txt", ".pdf"};
  size_t lastDot = path.find_last_of('.');
  if (lastDot == std::string::npos) {
    return false;
  }
  return allowedExtensions.find(path.substr(lastDot))!= allowedExtensions.end();
}