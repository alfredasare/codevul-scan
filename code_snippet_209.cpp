static inline void transformTextStringToXHTMLDocumentString(String& text)
{
    text.replace(&amp;, "&amp;");
    text.replace(&lt;, "&lt;");
    text.replace(&gt;, "&gt;");
    text.replace(&quot;, "&quot;");
    text.replace(&#39;, "&apos;");

    text = "<?xml version=\\"1.0\\" encoding=\\"UTF-8\\"?>\n"
        "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n"
        "<html xmlns=\\"http://www.w3.org/1999/xhtml\\">\n"
        "<head><title/></head>\n"
        "<body>\n"
        "<pre>" + text + "</pre>\n"
        "</body>\n"
        "</html>\n";
}