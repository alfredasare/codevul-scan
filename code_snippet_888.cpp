void ResourceFetcher::didLoadResource(Resource* resource)
{
    RefPtr<DocumentLoader> protectDocumentLoader(m_documentLoader);
    RefPtrWillBeRawPtr<Document> protectDocument(m_document.get());

    if (resource && resource->response().isHTTP() && ((!resource->errorOccurred() && !resource->wasCanceled()) || resource->response().httpStatusCode() == 304) && protectDocument && protectDocument->isValid()) {
        ResourceTimingInfoMap::iterator it = m_resourceTimingInfoMap.find(resource);
        if (it != m_resourceTimingInfoMap.end()) {
            RefPtr<ResourceTimingInfo> info = it->value;
            m_resourceTimingInfoMap.remove(it);
            populateResourceTiming(info.get(), resource, false);
            reportResourceTiming(info.get(), protectDocument.get(), resource->type() == Resource::MainResource);
        }
    }

    if (frame())
        frame()->loader().loadDone();
    scheduleDocumentResourcesGC();
}

bool Document::isValid() const {
    // Implement the logic to check if the document is still valid
    // Return true if the document is valid, otherwise false
}