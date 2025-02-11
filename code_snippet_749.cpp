CreateContextProviderOnWorkerThread(
Platform::ContextAttributes context_attributes,
Platform::GraphicsInfo* gl\_info,
bool* using\_gpu\_compositing,
const KURL& url) {
WaitableEvent waitable\_event;
ContextProviderCreationInfo creation\_info;
GURL safe\_url = GURL(url.ElidedString().Utf8()); // Validate and sanitize the URL using the GURL class.
if (!safe\_url.is\_valid()) {
return nullptr;
}
creation\_info.context\_attributes = context\_attributes;
creation\_info.gl\_info = gl\_info;
creation\_info.url = safe\_url; // Use the validated URL in the creation\_info struct.
creation\_info.using\_gpu\_compositing = using\_gpu\_compositing;
scoped\_refptr<WebTaskRunner> task\_runner =
Platform::Current()->MainThread()->GetWebTaskRunner();
PostCrossThreadTask(*task\_runner, FROM\_HERE,
CrossThreadBind(&CreateContextProviderOnMainThread,
CrossThreadUnretained(&creation\_info),
CrossThreadUnretained(&waitable\_event)));
waitable\_event.Wait();
return std::move(creation\_info.created\_context\_provider);
}