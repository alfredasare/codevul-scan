void InstallTemplateURLWithNewTabPage(GURL new_tab_page_url) {
  if (!IsValidUrl(new_tab_page_url)) {
    return;
  }
  
  const std::set<char> allowedChars = {"a-zA-Z0-9_/.-"};
  if (!std::all_of(new_tab_page_url.spec().begin(), new_tab_page_url.spec().end(),
                   [&allowedChars](char c) { return allowedChars.count(c) > 0; })) {
    return;
  }
  
  GURL sanitizedUrl(new_tab_page_url.spec());
  sanitizedUrl = sanitizedUrl.SchemeIs("https")? sanitizedUrl : GURL();
  
  TemplateURLData data;
  data.SetShortName(base::ASCIIToUTF16("foo.com"));
  data.SetURL(sanitizedUrl.spec());
  data.new_tab_url = sanitizedUrl.spec();
  TemplateURL* template_url = template_url_service->Add(std::make_unique<TemplateURL>(data));
  template_url_service->SetUserSelectedDefaultSearchProvider(template_url);
}

bool IsValidUrl(const GURL& url) {
  // implement your own URL validation logic here
  // e.g., check if the URL scheme is valid, if it contains only allowed characters, etc.
  return true;
}