Int Document::requestAnimationFrame(FrameRequestCallback* callback)
{
if (callback == nullptr) {
throw std::invalid\_argument("callback cannot be null");
}
return ensureScriptedAnimationController().registerCallback(callback);
}