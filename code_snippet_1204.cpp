std::string ExecuteManifestFetchTest(const std::string& url, const std::string& cross_origin) {
    if (!IsValidUrl(url)) {
        throw std::invalid_argument("Invalid URL");
    }
    if (!IsValidCrossOrigin(cross_origin)) {
        throw std::invalid_argument("Invalid cross-origin value");
    }
    std::string js(base::StringPrintf("reportOnFetch = false;");
    js += "var link = document.createElement('link');";
    js += "link.rel ='manifest';";
    js += "link.href = '%s';", url);
    if (!cross_origin.empty()) {
        js += "link.crossOrigin = '%s';", cross_origin);
    }
    js += "document.head.appendChild(link);";
    ExecuteJavaScriptForTests(js);
    return GetManifestAndIssuedRequests();
}

bool IsValidUrl(const std::string& url) {
    return url.find("http://") == 0 || url.find("https://") == 0;
}

bool IsValidCrossOrigin(const std::string& cross_origin) {
    static const std::set<std::string> allowed_cross_origins = {"*", "https://example.com"};
    return allowed_cross_origins.find(cross_origin)!= allowed_cross_origins.end();
}