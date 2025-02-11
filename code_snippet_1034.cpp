nsPluginInstance::NewStream(NPMIMEType /*type*/, NPStream* stream,
                            NPBool /*seekable*/, uint16_t* /*stype*/)
{

    if (_childpid) {
        return NPERR_GENERIC_ERROR;
    }

    // Fix: Limit the path to a restricted directory
    std::string safe_url = _window->correctedBaseURL(stream->url);
    _swf_url = safe_url;

    if (!_swf_url.empty() && _window) {
        return startProc();
    }

    return NPERR_NO_ERROR;
}