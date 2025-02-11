c++
nsPluginInstance::NewStream(NPMIMEType /*type*/, NPStream* stream,
                            NPBool /*seekable*/, uint16_t* /*stype*/)
{
    if (_childpid) {
        return NPERR_GENERIC_ERROR;
    }
    std::string swf_url = stream->url; 

    static const std::set<std::string> trusted_urls = {"https://example.com", "http://example.net"};
    if (!trusted_urls.count(swf_url)) {
        return NPERR_GENERIC_ERROR;
    }

    boost::replace_all(swf_url, "&amp;", "&");
    boost::replace_all(swf_url, "&lt;", "<");
    boost::replace_all(swf_url, "&gt;", ">");

    _swf_url = swf_url;

    if (!_swf_url.empty() && _window) {
        return startProc();
    }

    return NPERR_NO_ERROR;
}