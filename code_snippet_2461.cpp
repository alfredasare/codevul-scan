void WebUIBidiCheckerBrowserTestRTL::RunBidiCheckerOnPage(
const std::string& page\_url) {
acceptable\_schemes = {"http", "https"};
url\_components = gurl(page\_url);

if (url\_components.is\_valid() &&
std::find(acceptable\_schemes.begin(), acceptable\_schemes.end(), url\_components.scheme()) != acceptable\_schemes.end()) {
WebUIBidiCheckerBrowserTest::RunBidiCheckerOnPage(url\_components.spec(), true);
}
}