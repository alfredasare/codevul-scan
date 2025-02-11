void TabSpecificContentSettings::OnCookieChanged(
const GURL& url,
const GURL& frame\_url,
const std::string& cookie\_line,
const net::CookieOptions& options,
bool blocked\_by\_policy) {
if (blocked\_by\_policy && GURL(cookie\_line).is\_valid()) {
blocked\_local\_shared\_objects\_.cookies()->AddChangedCookie(
frame\_url, url, cookie\_line, options);
OnContentBlocked(CONTENT\_SETTINGS\_TYPE\_COOKIES, std::string());
} else if (!blocked\_by\_policy && GURL(cookie\_line).is\_valid()) {
allowed\_local\_shared\_objects\_.cookies()->AddChangedCookie(
frame\_url, url, cookie\_line, options);
OnContentAccessed(CONTENT\_SETTINGS\_TYPE\_COOKIES);
}

NotifySiteDataObservers();
}