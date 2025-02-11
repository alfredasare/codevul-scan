std::string ExecuteManifestFetchTest(const std::string& url,
                                   const std::string& cross_origin) {
    if (!base::ValidateScheme(url, net::HttpNetworkSession::SCHEME_HTTPS)) {
      return "";
    }
    std::string js(
        base::StringPrintf("reportOnFetch = false;"
                           "var link = document.createElement('link');"
                           "link.rel = 'manifest';"
                           "link.href = '%s';",
                           url.c_str()));
    if (!cross_origin.empty() && cross_origin == "anonymous") {
      js += "link.crossOrigin = 'anonymous';";
    }
    js += "document.head.appendChild(link);";
    ExecuteJavaScriptForTests(js);
    return GetManifestAndIssuedRequests();
}