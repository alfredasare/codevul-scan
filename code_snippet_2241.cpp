#include <boost/url.hpp>
#include <stdexcept>

void WebUIBidiCheckerBrowserTestRTL::RunBidiCheckerOnPage(const std::string& page_url) {
  static const std::set<std::string> allowed_urls = {"https://example.com/*", "http://example.org/*"};

  boost::url parsed_url;
  if (!parsed_url.parse(page_url)) {
    throw std::invalid_argument("Invalid URL: " + page_url);
  }

  if (allowed_urls.find(parsed_url.scheme() + "://" + parsed_url.host() + parsed_url.path()) == allowed_urls.end()) {
    throw std::runtime_error("Unauthorized URL: " + page_url);
  }

  WebUIBidiCheckerBrowserTest::RunBidiCheckerOnPage(page_url, true);
}