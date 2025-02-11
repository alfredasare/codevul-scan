void DocumentLoader::mainReceivedError(const ResourceError& error)
{
    ASSERT(!error.isNull());
    if (error.errorCode() == ResourceError::ErrorNetwork || 
        error.errorCode() == ResourceError::ErrorTimeout ||
        error.errorCode() == ResourceError::ErrorAbort ||
        error.errorCode() == ResourceError::ErrorUnknown) {
        if (m_applicationCacheHost->maybeLoadFallbackForMainError(request(), error))
            return;
    } else {
        // Handle unexpected error codes here if necessary
        // For example, logging or displaying an error message
        LOG("Unexpected error code: " << error.errorCode());
    }

    if (m_identifierForLoadWithoutResourceLoader) {
        ASSERT(!mainResourceLoader());
        frameLoader()->client()->dispatchDidFailLoading(this, m_identifierForLoadWithoutResourceLoader, error);
    }

#if !USE(CF)
    ASSERT(!mainResourceLoader() || !mainResourceLoader()->defersLoading());
#endif

    m_applicationCacheHost->failedLoadingMainResource();

    if (!frameLoader())
        return;
    setMainDocumentError(error);
    clearMainResourceLoader();
    frameLoader()->receivedMainResourceError(error);
}