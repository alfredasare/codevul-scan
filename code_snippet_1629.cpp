bool PermissionsData::CanAccessPage(const GURL& document_url,
int tab\_id,
std::string\* error) const {
if (!document\_url.is\_valid()) {
*error = "Invalid document URL";
return false;
}

PageAccess result = GetPageAccess(document\_url, tab\_id, error);

return result == PageAccess::kAllowed || result == PageAccess::kWithheld;
}