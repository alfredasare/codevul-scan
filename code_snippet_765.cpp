code:


void PageInfo::OnRevokeSSLErrorBypassButtonPressed() {
  DCHECK(chrome_ssl_host_state_delegate_);
  
  xml::ParserSettings settings;
  settings.setExternalEntityLoading(false);
  xml::Document doc = xml::parseString(chrome_ssl_host_state_delegate_->getXml(), settings);
  
  chrome_ssl_host_state_delegate_->RevokeUserAllowExceptionsHard(doc.getDocumentElement()->getAttribute("site_url").getHost());
  did_revoke_user_ssl_decisions_ = true;
}