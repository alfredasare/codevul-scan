void LocalFileSystem::resolveURLInternal(
    PassRefPtrWillBeRawPtr<ExecutionContext> context,
    const KURL& fileSystemURL,
    PassRefPtr<CallbackWrapper> callbacks)
{
    if (!fileSystem()) {
        fileSystemNotAvailable(context, callbacks);
        return;
    }

    // Normalize the URL and validate input
    KURL normalizedURL(ParsedResourceResponse::create().setURL(fileSystemURL));
    if (normalizedURL.isValid() && normalizedURL.hasProtocol("file") && !normalizedURL.isEmpty()) {
        KURL resolvedURL = KURL(KURL(), normalizedURL.path());
        if (resolvedURL.isLocalFile()) {
            fileSystem()->resolveURL(resolvedURL, callbacks->release());
            return;
        }
    }

    // Reject the request if input validation or normalization fails
    fileSystemNotAvailable(context, callbacks);
}