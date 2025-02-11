void PageSerializer::addImageToResources(ImageResource* image, LayoutObject* imageLayoutObject, const KURL& url)
{
    if (!shouldAddURL(url))
        return;

    // Validate the URL
    if (!isValidURL(url)) {
        LOG_ERROR("Invalid URL: " + url.toString());
        return;
    }

    // Whitelist allowed URLs
    if (!isAllowedURL(url)) {
        LOG_ERROR("URL not allowed: " + url.toString());
        return;
    }

    // Normalize the URL (optional)
    url = normalizeURL(url);

    if (!image ||!image->hasImage() || image->errorOccurred())
        return;

    RefPtr<SharedBuffer> data = imageLayoutObject? image->imageForLayoutObject(imageLayoutObject)->data() : nullptr;
    if (!data)
        data = image->image()->data();

    addToResources(image, data, url);
}