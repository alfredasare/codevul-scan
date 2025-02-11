bool WebLocalFrameImpl::IsViewSourceModeEnabled() const {
    if (!GetFrame())
        return false;

    Frame* currentFrame = GetFrame();
    while (currentFrame && !currentFrame->InViewSourceMode())
        currentFrame = currentFrame->TraversalParent();

    return currentFrame != nullptr;
}