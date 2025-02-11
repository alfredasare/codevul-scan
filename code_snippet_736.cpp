WebPageProxy* webkitWebViewBaseGetPage(WebKitWebViewBase* webkitWebViewBase)
{
    auto pageProxy = std::make_unique<WebPageProxy>(webkitWebViewBase->priv->pageProxy);
    return pageProxy.get();
}