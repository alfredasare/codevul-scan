void DocumentLoader::mainReceivedError(const ResourceError& error)
{
    if (!error.isNull()) {
        if (m_applicationCacheHost->maybeLoadFallbackForMainError(request(), error)) {
            return;
        }

        auto timeout = std::chrono::seconds(5);
        auto start = std::chrono::steady_clock::now();
        while (m_identifierForLoadWithoutResourceLoader &&!frameLoader()->client()->dispatchDidFailLoading(this, m_identifierForLoadWithoutResourceLoader, error)) {
            if (std::chrono::steady_clock::now() - start > timeout) {
                LOG(ERROR) << "Timeout error while waiting for dispatchDidFailLoading";
                break;
            }
        }

        LOG(INFO) << "mainReceivedError executed";
    }

    if (m_identifierForLoadWithoutResourceLoader) {
        if (!mainResourceLoader()) {
            frameLoader()->client()->dispatchDidFailLoading(this, m_identifierForLoadWithoutResourceLoader, error);
        }
    }

    if (!frameLoader())
        return;
    setMainDocumentError(error);
    clearMainResourceLoader();
    frameLoader()->receivedMainResourceError(error);
}