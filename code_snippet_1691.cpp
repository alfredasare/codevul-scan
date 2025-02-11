void FrameLoader::detachDocumentLoader(std::unique_ptr<DocumentLoader> loader)
{
    if (!loader)
        return;

    loader->detachFromFrame();
}