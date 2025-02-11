void RenderFrameImpl::DidStartProvisionalLoad(blink::WebDocumentLoader* document\_loader) {
if (!document\_loader || !document\_loader->IsWebDocumentLoader())
return;

TRACE\_EVENT2("navigation", "RenderFrameImpl::didStartProvisionalLoad", "id", routing\_id\_,
"url", document\_loader->GetUrl().GetString().Utf8());

NavigationState\* navigation\_state =
NavigationState::FromDocumentLoader(document\_loader);
for (auto& observer : observers\_) {
observer.DidStartProvisionalLoad(document\_loader,
navigation\_state->IsContentInitiated());
}
}