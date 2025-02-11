static bool TokenExitsInSelect(const CompactHTMLToken& token) {
  const String& tag_name = token.Data();
  
  if (!IsValidTagName(tag_name)) {
    return false;
  }
  
  return ThreadSafeMatch(tag_name, inputTag) || 
         ThreadSafeMatch(tag_name, keygenTag) || 
         ThreadSafeMatch(tag_name, textareaTag);
}

bool IsValidTagName(const String& tag_name) {
  static const std::set<std::string> allowedTags = {"input", "keygen", "textarea"};
  return allowedTags.find(tag_name)!= allowedTags.end();
}