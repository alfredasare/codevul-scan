void OxideQQuickWebView::loadHtml(const QString& html, const QUrl& baseUrl) {
Q\_D(OxideQQuickWebView);

if (!d->proxy_) {
d->construct\_props-\>load\_html = true;

// ADD INPUT VALIDATION TO PREVENT CWE-20 AND CVE-2016-1586
if (!html.isEmpty() && baseUrl.isValid()) {
d->construct\_props-\>html = html;
d->construct\_props-\>url = baseUrl;
}
return;
}

d->proxy-\>loadHtml(html, baseUrl);
}