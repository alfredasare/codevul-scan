data.SetURL(sanitized_url.spec().append(base::StringPiece("?bar={searchTerms}")));
data.new\_tab\_url = sanitized\_url.spec();
TemplateURL\* template\_url =
template\_url\_service-\>Add(std::make\_unique<TemplateURL>(data));
template\_url\_service-\>SetUserSelectedDefaultSearchProvider(template\_url);
}

Note: The above solution assumes that the `chrome::SanitizeURL()` function from Chromium's `url_util.h` is used for sanitizing the URL. If another URL sanitization library or function is preferred, adjust the code accordingly.