void ResourceFetcher::didLoadResource(Resource* resource)
{
    RefPtr<DocumentLoader> protectDocumentLoader(m_documentLoader);
    RefPtrWillBeRawPtr<Document> protectDocument(m_document.get());

    if (resource && resource->response().isHTTP() && ((!resource->errorOccurred() &&!resource->wasCanceled()) || resource->response().httpStatusCode() == 304) && document()) {
        auto it = m_resourceTimingInfoMap.find(resource);
        if (it!= m_resourceTimingInfoMap.end()) {
            RefPtr<ResourceTimingInfo> info = it->value;
            m_resourceTimingInfoMap.erase(it); // Use erase instead of remove
            populateResourceTiming(info.get(), resource, false);
            reportResourceTiming(info.get(), document(), resource->type() == Resource::MainResource);
        }
    }

    if (frame())
        frame()->loader().loadDone();
    scheduleDocumentResourcesGC();
}