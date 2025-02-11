void RunTest(const GURL& url) {
    // Validate the URL using a regular expression
    if (!url_is_valid(url)) {
        LOG(ERROR) << "Invalid URL: " << url;
        return;
    }

    ui_test_utils::NavigateToURL(browser(), url);
    content::WebContents* web_contents = browser()->tab_strip_model()->GetActiveWebContents();
    ASSERT_TRUE(web_contents);
    EXPECT_TRUE(ExecuteWebUIResourceTest(web_contents, include_libraries_));
}

bool url_is_valid(const GURL& url) {
    static const std::regex valid_url_regex(
        R"((https?|ftp)://[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}
         \b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)?)");
    return std::regex_match(url.spec(), valid_url_regex);
}