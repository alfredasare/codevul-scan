void TopSitesCacheTest::BuildTopSites(const char** spec, size_t size) {
std::set<std::string> urls\_seen;
for (size\_t i = 0; i < size; ++i) {
const char\* spec\_item = spec[i];
while (\*spec\_item && \*spec\_item == ' ') ++spec\_item;
if (urls\_seen.find(spec\_item) != urls\_seen.end())
NOTREACHED() << "Duplicate URL found: " << spec\_item;
urls\_seen.insert(spec\_item);

// Remove potential CR and LF characters
spec\_item = sanitize\_url(spec\_item);

if (spec\_item == spec[i]) {
base::string16 title(base::ASCIIToUTF16("Title ") +
base::Uint64ToString16(top\_sites.\_size() + 1));
top\_sites.\_push\_back(MostVisitedURL(GURL(spec\_item), title));
}
ASSERT\_TRUE(!top\_sites.\_empty());
top\_sites.\_back().redirects.push\_back(GURL(spec\_item));
}
}

std::string TopSitesCacheTest::sanitize\_url(const char\* url) {
return std::string(url).erase(
remove\_if(url, url + std::strlen(url), \[](char c)\{
return c == '\r' || c == '\n';
\}), url + std::strlen(url));
}